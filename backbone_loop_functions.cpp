#include "backbone_loop_functions.h"
#include <argos3/core/simulator/simulator.h>
#include <argos3/core/utility/configuration/argos_configuration.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>

CBackboneLoopFunctions::CBackboneLoopFunctions() :
   m_pcFloor(NULL){
}

void CBackboneLoopFunctions::Init(TConfigurationNode& t_node){
  try{
    m_pcFloor = &GetSpace().GetFloorEntity();
  }
  catch(CARGoSException& ex) {
      THROW_ARGOSEXCEPTION_NESTED("Error parsing loop functions!", ex);
   }
}

void CBackboneLoopFunctions::Reset(){
  //m_cOutput.close();
}

void CBackboneLoopFunctions::Destroy(){
  //m_cOutput.close();
}

CColor CBackboneLoopFunctions::GetFloorColor(const CVector2& c_position_on_plane) {
   //if(c_position_on_plane.GetX() < -1.0f) {
   if(c_position_on_plane.GetX() < 1.5f && c_position_on_plane.GetX() > -0.5f &&
      c_position_on_plane.GetY() > -0.5f && c_position_on_plane.GetY() < 1.5f){
      return CColor::GRAY50;
   }
   return CColor::WHITE;
}

void CBackboneLoopFunctions::PreStep() {
  m_pcFloor->SetChanged();
}

REGISTER_LOOP_FUNCTIONS(CBackboneLoopFunctions, "backbone_loop_functions")
