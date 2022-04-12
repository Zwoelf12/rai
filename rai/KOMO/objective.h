/*  ------------------------------------------------------------------
    Copyright (c) 2011-2020 Marc Toussaint
    email: toussaint@tu-berlin.de

    This code is distributed under the MIT License.
    Please see <root-path>/LICENSE for details.
    --------------------------------------------------------------  */

#pragma once

#include "../Optim/NLP.h"
#include "../Kin/feature.h"

//===========================================================================

struct Objective {
  std::shared_ptr<Feature> feat;
  ObjectiveType type;  ///< element of {f, sumOfSqr, inequality, equality}
  rai::String name;
  arr times;

  Objective(const ptr<Feature>& _feat, const ObjectiveType& _type, const rai::String& _name, const arr& _times)
    : feat(_feat), type(_type), name(_name), times(_times) {}

  bool activeAtTime(double time);
  void write(std::ostream& os) const;
};
stdOutPipe(Objective)

//===========================================================================

struct GroundedObjective {
  std::shared_ptr<Feature> feat;
  const rai::Enum<ObjectiveType> type;  ///< element of {f, sumOfSqr, inequality, equality}
  FrameL frames;
  intA timeSlices;
  int objId=-1;

  GroundedObjective(const ptr<Feature>& _feat, const ObjectiveType& _type, const intA& _timeSlices) : feat(_feat), type(_type), timeSlices(_timeSlices) {}
  ~GroundedObjective() {}

  rai::String name(){ return feat->shortTag(frames.first()->C); }
};

//===========================================================================

struct ObjectiveL : rai::Array<shared_ptr<Objective>>{

  ptr<struct Objective> add(const arr& times, const ptr<Feature>& f, ObjectiveType type, const char* name=0);

  ptr<struct Objective> add(const arr& times,
                            const ptr<Feature>& f, const rai::Configuration& C, const StringA& frames,
                            ObjectiveType type, const arr& scale=NoArr, const arr& target=NoArr, int order=-1, int deltaFromStep=0, int deltaToStep=0);

  ptr<struct Objective> add(const arr& times,
                            const FeatureSymbol& feat,  const rai::Configuration& C, const StringA& frames,
                            ObjectiveType type, const arr& scale=NoArr, const arr& target=NoArr, int order=-1, int deltaFromStep=0, int deltaToStep=0);

  double maxError(const rai::Configuration& C, double time, int verbose=0) const;
};
