# NOTE: This file is generated by yotta: changes will be overwritten!

cmake_minimum_required(VERSION 2.8.11)

include_directories("/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/source")


set(YOTTA_AUTO_BLE_CPP_FILES
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/source/BLE.cpp"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/source/DiscoveredCharacteristic.cpp"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/source/services/URIBeaconConfigService.cpp"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/source/services/DFUService.cpp"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/source/GapScanningParams.cpp"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/source/services/UARTService.cpp"
)
# force dependency on the config header for cpp files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BLE_CPP_FILES} PROPERTY OBJECT_DEPENDS "/Users/Elliot/Documents/Internship/BeeBit/build/bbc-microbit-classic-gcc/yotta_config.h")
set(YOTTA_AUTO_BLE_HEADER_FILES
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/FunctionPointerWithContext.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GapScanningParams.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/HeartRateService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/BLE.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/CallChainOfFunctionPointersWithContext.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/BLEInstanceBase.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/Gap.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GapAdvertisingParams.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/LinkLossService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/DeviceInformationService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/SecurityManager.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GattServer.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/HealthThermometerService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/DiscoveredCharacteristicDescriptor.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GattAttribute.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GattCharacteristic.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/DFUService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/ServiceDiscovery.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GattClient.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/DiscoveredCharacteristic.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/URIBeaconConfigService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/DiscoveredService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/deprecate.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GattServerEvents.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/iBeacon.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GattService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/UUID.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/BLEProtocol.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/EnvironmentalService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/EddystoneService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/BatteryService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GattCallbackParamTypes.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/UARTService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/SafeBool.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GapEvents.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/CharacteristicDescriptorDiscovery.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/services/EddystoneConfigService.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/blecommon.h"
    "/Users/Elliot/Documents/Internship/BeeBit/yotta_modules/ble/ble/GapAdvertisingData.h"
)
# force dependency on the config header for header files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BLE_HEADER_FILES} PROPERTY OBJECT_DEPENDS "/Users/Elliot/Documents/Internship/BeeBit/build/bbc-microbit-classic-gcc/yotta_config.h")


add_library(ble
    ${YOTTA_AUTO_BLE_CPP_FILES}
    ${YOTTA_AUTO_BLE_HEADER_FILES}
)

yotta_postprocess_target(LIBRARY ble)



target_link_libraries(ble
    ble-nrf51822
    mbed-classic
)

