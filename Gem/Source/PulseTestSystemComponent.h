
#pragma once

#include <AzCore/Component/Component.h>

#include <PulseTest/PulseTestBus.h>

namespace PulseTest
{
    class PulseTestSystemComponent
        : public AZ::Component
        , protected PulseTestRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PulseTestSystemComponent, "{7B66884C-C659-4834-962E-D00A5DA83B75}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        PulseTestSystemComponent();
        ~PulseTestSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PulseTestRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
