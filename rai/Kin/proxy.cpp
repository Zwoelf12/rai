#include "proxy.h"

#include <Gui/opengl.h>
#include "kin.h"
#include "frame.h"

//===========================================================================
//
// Proxy
//

mlr::Proxy::Proxy() {
}

mlr::Proxy::~Proxy() {
  del_coll();
}


void mlr::Proxy::calc_coll(const KinematicWorld& K){
  mlr::Shape *s1 = K.frames(a)->shape;
  mlr::Shape *s2 = K.frames(b)->shape;

  double r1=s1->size(3);
  double r2=s2->size(3);
  mlr::Mesh *m1 = &s1->sscCore();  if(!m1->V.N){ m1 = &s1->mesh(); r1=0.; }
  mlr::Mesh *m2 = &s2->sscCore();  if(!m2->V.N){ m2 = &s2->mesh(); r2=0.; }
  coll = new PairCollision(*m1, *m2, s1->frame.X, s2->frame.X, r1, r2);
}

typedef mlr::Array<mlr::Proxy*> ProxyL;

#ifdef MLR_GL
void mlr::Proxy::glDraw(OpenGL& gl){
  if(coll){
    glLoadIdentity();
    coll->glDraw(gl);
  }else{
    glLoadIdentity();
    if(!colorCode){
      if(d>0.) glColor(.8,.2,.2);
      else glColor(1,0,0);
    }else glColor(colorCode);
    glBegin(GL_LINES);
    glVertex3dv(posA.p());
    glVertex3dv(posB.p());
    glEnd();
    glDisable(GL_CULL_FACE);
    mlr::Transformation f;
    f.pos=posA;
    f.rot.setDiff(mlr::Vector(0, 0, 1), posA-posB);
    double GLmatrix[16];
    f.getAffineMatrixGL(GLmatrix);
    glLoadMatrixd(GLmatrix);
    glDrawDisk(.02);

    f.pos=posB;
    f.getAffineMatrixGL(GLmatrix);
    glLoadMatrixd(GLmatrix);
    glDrawDisk(.02);

//    f.pos=.5*(posA+posB);
//    f.getAffineMatrixGL(GLmatrix);
//    glLoadMatrixd(GLmatrix);
//    glDrawText(STRING(a <<'-' <<b <<':' <<d), 0.,0.,0.);

    glEnable(GL_CULL_FACE);
  }
}
#endif

