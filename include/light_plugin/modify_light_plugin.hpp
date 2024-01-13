#ifndef Modify_Light_Plugin_HPP
#define Modify_Light_Plugin_HPP

#include <gz/sim/System.hh>

namespace modify_light_plugin {
    class ModifyLightPlugin:
        public gz::sim::System, 
        // public gz::sim::ISystemConfigure,
        public gz::sim::ISystemPreUpdate
    {
        public:
            ModifyLightPlugin();
            ~ModifyLightPlugin() override;

            // void Configure(const gz::sim::Entity &_entity, const std::shared_ptr<const sdf::Element> &_sdf,
            //     gz::sim::EntityComponentManager &_ecm, gz::sim::EventManager &_eventMgr) override;
            void PreUpdate(const gz::sim::UpdateInfo &_info, gz::sim::EntityComponentManager &_ecm) override;

    };
}


#endif