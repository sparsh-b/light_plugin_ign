#include "light_plugin/modify_light_plugin.hpp"
#include <gz/plugin/Register.hh>

IGNITION_ADD_PLUGIN(
    modify_light_plugin::ModifyLightPlugin,
    gz::sim::System,
    // modify_light_plugin::ModifyLightPlugin::ISystemConfigure,
    modify_light_plugin::ModifyLightPlugin::ISystemPreUpdate
)

using namespace modify_light_plugin;

ModifyLightPlugin::ModifyLightPlugin() 
{

}
ModifyLightPlugin::~ModifyLightPlugin() 
{

}

// void Configure(const gz::sim::Entity &_entity, const std::shared_ptr<const sdf::Element> &_sdf,
//                 gz::sim::EntityComponentManager &_ecm, gz::sim::EventManager &_eventMgr) 
// {
//     ignmsg << "\n\nInside Configure\n\n";
// }

void ModifyLightPlugin::PreUpdate(const gz::sim::UpdateInfo &_info, 
    gz::sim::EntityComponentManager &_ecm)
{
    ignmsg << "Inside PreUpdate\n";
}