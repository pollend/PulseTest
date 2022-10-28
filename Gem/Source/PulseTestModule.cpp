
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "PulseTestSystemComponent.h"

namespace PulseTest
{
    class PulseTestModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(PulseTestModule, "{E45B6F9B-268C-4728-8525-597304BA2155}", AZ::Module);
        AZ_CLASS_ALLOCATOR(PulseTestModule, AZ::SystemAllocator, 0);

        PulseTestModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PulseTestSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PulseTestSystemComponent>(),
            };
        }
    };
}// namespace PulseTest

AZ_DECLARE_MODULE_CLASS(Gem_PulseTest, PulseTest::PulseTestModule)
