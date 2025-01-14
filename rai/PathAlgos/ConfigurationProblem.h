#pragma once

#include <Kin/kin.h>
#include <KOMO/objective.h>
#include <Optim/NLP.h>

#include <unordered_map>

struct ConfigurationProblem;

struct QueryResult{
  //goal features
  arr goal_y, goal_J;

  //collision features
  uintA collisions;
  arr coll_y, coll_J;
  arr normal_y, normal_J;
  arr side_J;

  bool isGoal=true;
  bool isFeasible=true;

  //optional a 3D coordinate for display
  arr disp3d;

  void getViolatedContacts(arr& y, arr& J, double margin=0.);
  arr getSideStep();
  arr getForwardStep();
  arr getBackwardStep(double relativeStepLength=1.1, double margin=0., const arr& nullRef=NoArr); //1.1 means overstepping the constraint IK a bit

  void write(ostream& os) const;
  void writeDetails(ostream& os, const ConfigurationProblem& P, double margin=0.) const;
};
stdOutPipe(QueryResult)

struct ConfigurationProblem {
  rai::Configuration C;
  arr q0, limits, max_step;

  //what constraints are evaluated?
  rai::Array<shared_ptr<GroundedObjective>> objectives;

  //what collisions are evaluated?
  bool computeAllCollisions;
  uintA collisionPairs;
  double collisionTolerance;

  //user info
  int verbose=0; //-> verbose
  uint evals=0;

  ConfigurationProblem(const rai::Configuration& _C, bool _computeCollisions=true, double _collisionTolerance=1e-3);

  shared_ptr<GroundedObjective> addObjective(const FeatureSymbol& feat, const StringA& frames, ObjectiveType type, const arr& scale=NoArr, const arr& target=NoArr);
  void setExplicitCollisionPairs(const StringA& _collisionPairs);

  shared_ptr<QueryResult> query(const arr& x);
};
