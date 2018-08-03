/*  ------------------------------------------------------------------
    Copyright (c) 2017 Marc Toussaint
    email: marc.toussaint@informatik.uni-stuttgart.de

    This code is distributed under the MIT License.
    Please see <root-path>/LICENSE for details.
    --------------------------------------------------------------  */

#include "TM_physics.h"
#include <Kin/flag.h>
#include <Kin/frame.h>
#include <Kin/contact.h>
#include <Kin/TM_default.h>
#include <Kin/TM_angVel.h>
#include <Kin/TM_PairCollision.h>

void shapeFunction(double &x, double &dx);


TM_NewtonEuler::TM_NewtonEuler(int iShape) : i(iShape) {
  order=2;
  gravity = rai::getParameter<double>("TM_Physics/gravity", 9.81);
}

void TM_NewtonEuler::phi(arr &y, arr &J, const WorldL &Ktuple) {
  CHECK_EQ(order, 2, "");

  //this is the direct impuls exchange case, where NewtonEuler is switched off
  if((Ktuple(-1)->frames(i)->flags & (1<<FL_impulseExchange))){
    y.resize(6).setZero();
    if(&J) J.resize(6, getKtupleDim(Ktuple).last()).setZero();
    return;
  }

  //get linear and angular accelerations
  arr acc, Jacc, wcc, Jwcc;
  TM_Default pos(TMT_posDiff, i);
  pos.order=2;
  pos.Feature::phi(acc, (&J?Jacc:NoArr), Ktuple);
  acc(2) += gravity;

  TM_AngVel rot(i);
  rot.order=2;
  rot.phi(wcc, (&J?Jwcc:NoArr), Ktuple);


  rai::KinematicWorld& K = *Ktuple(-2); // ! THIS IS THE MID TIME SLICE !
  rai::Frame *a = K.frames(i);
  for(rai::Contact *c:a->contacts){
    double sign = +1.;
    CHECK(&c->a==a || &c->b==a, "");
    if(&c->b==a) sign=-1.;

    arr f, Jf;
    K.kinematicsForce(f, Jf, c);
    if(&J) expandJacobian(Jf, Ktuple, -2);

//    arr d, Jd;
//    TM_PairCollision dist(con->a.ID, con->b.ID, TM_PairCollision::_normal, false);
//    dist.phi(d, (&J?Jd:NoArr), K);
//    con->y = d.scalar();
//    con->setFromPairCollision(*dist.coll);

    arr cp, Jcp;
    K.kinematicsVec(cp, Jcp, a, c->b_rel); //contact point VECTOR only
    if(&J) expandJacobian(Jcp, Ktuple, -2);

    acc += sign * 20. * c->force;
//        wcc -= .1 * crossProduct((a->X.rot*c->b_rel).getArr(), c->force);
    wcc -= sign * 2. * crossProduct(cp, c->force);
    if(&J){
      Jacc += sign * 20. * Jf;
      Jwcc -= sign * 2. * (skew(cp) * Jf - skew(c->force) * Jcp);
    }
  }
        
  y.resize(6).setZero();
  y.setVectorBlock(acc, 0);
  y.setVectorBlock(wcc, 3);

  if(&J) {
    J.resize(6, Jacc.d1).setZero();
    J.setMatrixBlock(Jacc, 0, 0);
    J.setMatrixBlock(Jwcc, 3, 0);
  }
}

