#ifndef BACKBONE_LOOP_FUNCTIONS_H
#define BACKBONE_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/core/simulator/entity/floor_entity.h>
#include <argos3/core/utility/math/range.h>
#include <argos3/core/utility/math/rng.h>

using namespace argos;

class CBackboneLoopFunctions : public CLoopFunctions{
public:
  CBackboneLoopFunctions();
  virtual ~CBackboneLoopFunctions(){}


  virtual void Init(TConfigurationNode& t_tree);
  virtual void Reset();
  virtual void Destroy();
  virtual CColor GetFloorColor(const CVector2& c_position_on_plane);
  virtual void PreStep();

private:
  CFloorEntity* m_pcFloor;
};

#endif
