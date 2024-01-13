#include "light_plugin/modify_light_plugin.hpp"
#include <gz/plugin/Register.hh>

#include <ignition/gazebo/components/Light.hh>
#include <ignition/gazebo/components/LightCmd.hh>
#include <ignition/msgs.hh>
#include <ignition/transport.hh>


IGNITION_ADD_PLUGIN(
    modify_light_plugin::ModifyLightPlugin,
    gz::sim::System,
    // modify_light_plugin::ModifyLightPlugin::ISystemConfigure,
    modify_light_plugin::ModifyLightPlugin::ISystemPreUpdate
)

using namespace modify_light_plugin;

ModifyLightPlugin::ModifyLightPlugin() 
{
    this->light_intensity = 1.0;
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
    ignition::transport::Node node;

    // timeout used for services
    constexpr unsigned int timeout = 5000;

    ignmsg << "Inside PreUpdate\n";

    bool result;
    ignition::msgs::Boolean response;
    ignition::msgs::Light lightRequest;
    auto lightConfigService = "/world/sphere_light_world/light_config";
    // TODO: read world's name automatically from the sdf file

    this->light_intensity -= 0.1;
    if (this->light_intensity < 0) this->light_intensity = 1.0;
    auto color = ignition::math::Color(this->light_intensity, this->light_intensity, 
        this->light_intensity, 1);

    //! [modify light]
    lightRequest.set_name("light1");
    lightRequest.set_range(100);
    lightRequest.set_attenuation_linear(0.01);
    lightRequest.set_attenuation_constant(0.9);
    lightRequest.set_attenuation_quadratic(0.001);
    lightRequest.set_cast_shadows(true);
    lightRequest.set_type(ignition::msgs::Light::SPOT);
    lightRequest.set_spot_inner_angle(0.1);
    lightRequest.set_spot_outer_angle(0.5);
    lightRequest.set_spot_falloff(0.80000000000000004);
    ignition::msgs::Set(lightRequest.mutable_pose(),
      ignition::math::Pose3d(0.0, 0.0, 2.0, 0.0, 0.0, 0.0));
    ignition::msgs::Set(lightRequest.mutable_diffuse(), color);
    ignition::msgs::Set(lightRequest.mutable_specular(), color);
    //! [modify light]

    bool executed = node.Request(lightConfigService, lightRequest, timeout, response, result);
    std::cout << "Service called" << std::endl;

    if (executed)
    {
      if (result)
        std::cout << "Response: [" << response.data() << "]" << std::endl;
      else
        std::cout << "Service call failed" << std::endl;
    }
    else
      std::cerr << "Service call timed out" << std::endl;


}
