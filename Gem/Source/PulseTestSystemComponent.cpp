
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "PulseTestSystemComponent.h"

namespace PulseTest
{
    void PulseTestSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PulseTestSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PulseTestSystemComponent>("PulseTest", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PulseTestSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PulseTestService"));
    }

    void PulseTestSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PulseTestService"));
    }

    void PulseTestSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void PulseTestSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    PulseTestSystemComponent::PulseTestSystemComponent()
    {
        if (PulseTestInterface::Get() == nullptr)
        {
            PulseTestInterface::Register(this);
        }
    }

    PulseTestSystemComponent::~PulseTestSystemComponent()
    {
        if (PulseTestInterface::Get() == this)
        {
            PulseTestInterface::Unregister(this);
        }
    }

    void PulseTestSystemComponent::Init()
    {
    }

    void PulseTestSystemComponent::Activate()
    {
        PulseTestRequestBus::Handler::BusConnect();
    }

    void PulseTestSystemComponent::Deactivate()
    {
        PulseTestRequestBus::Handler::BusDisconnect();
    }
}
