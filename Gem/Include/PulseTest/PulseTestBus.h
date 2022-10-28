
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace PulseTest
{
    class PulseTestRequests
    {
    public:
        AZ_RTTI(PulseTestRequests, "{AF598082-0E63-4DC5-9C4E-3C06B1A8DEAF}");
        virtual ~PulseTestRequests() = default;
        // Put your public methods here
    };

    class PulseTestBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using PulseTestRequestBus = AZ::EBus<PulseTestRequests, PulseTestBusTraits>;
    using PulseTestInterface = AZ::Interface<PulseTestRequests>;

} // namespace PulseTest
