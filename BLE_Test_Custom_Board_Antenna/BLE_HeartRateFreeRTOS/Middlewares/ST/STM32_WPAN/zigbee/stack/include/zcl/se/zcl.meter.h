/**
 * @file zcl.meter.h
 * @brief ZCL Metering cluster header
 * ZCL 7 section 10.4
 * ZCL 8 section 10.4
 * @copyright Copyright [2009 - 2020] Exegin Technologies Limited. All rights reserved.
 */

#ifndef ZCL_METER_H
# define ZCL_METER_H

#include "zcl/zcl.h"

/*lint -save -e621 [ identifier clash within 31 chars <Rule 5.1, REQUIRED> ] */

/** Metering Server Attribute IDs */
enum ZbZclMeteringSvrAttrT {
    /* Reading Information Set (0x00) */
    ZCL_METER_SVR_ATTR_CURSUM_DELIV = 0x0000, /**< CurrentSummationDelivered */
    ZCL_METER_SVR_ATTR_CURSUM_RECV = 0x0001, /**< CurrentSummationReceived (Optional) */
    ZCL_METER_SVR_ATTR_MAX_DMND_DELIV = 0x0002, /**< CurrentMaxDemandDelivered (Optional) */
    ZCL_METER_SVR_ATTR_MAX_DMND_RECV = 0x0003, /**< CurrentMaxDemandReceived (Optional) */
    ZCL_METER_SVR_ATTR_DFT_SUM = 0x0004, /**< DFTSummation (Optional) */
    ZCL_METER_SVR_ATTR_DAILY_FREEZE_TIME = 0x0005, /**< DailyFreezeTime (Optional) */
    ZCL_METER_SVR_ATTR_POWER_FACTOR = 0x0006, /**< PowerFactor (Optional) */
    ZCL_METER_SVR_ATTR_READ_SNAPSHOT_TIME = 0x0007, /**< ReadingSnapShotTime (Optional) */
    ZCL_METER_SVR_ATTR_MAX_DMND_DELIV_TIME = 0x0008, /**< CurrentMaxDemandDeliveredTime (Optional) */
    ZCL_METER_SVR_ATTR_MAX_DMND_RECV_TIME = 0x0009, /**< CurrentMaxDemandReceivedTime (Optional) */
    ZCL_METER_SVR_ATTR_DEFAULT_UPDATE_PERIOD = 0x000a, /**< DefaultUpdatePeriod (Optional) */
    ZCL_METER_SVR_ATTR_FAST_POLL_UPDATE_PERIOD = 0x000b, /**< FastPollUpdatePeriod (Optional) */
    ZCL_METER_SVR_ATTR_BLOCK_CONSUMP_DELIV = 0x000c, /**< CurrentBlockPeriodConsumptionDelivered (Optional) */
    ZCL_METER_SVR_ATTR_DAILY_CONSUMPTION_TARGET = 0x000d, /**< DailyConsumptionTarget (Optional) */
    ZCL_METER_SVR_ATTR_CURBLOCK = 0x000e, /**< CurrentBlock (Optional) */
    ZCL_METER_SVR_ATTR_PROFILE_INTERVAL_PERIOD = 0x000f, /**< ProfileIntervalPeriod (Optional) */
    ZCL_METER_SVR_ATTR_INTERVAL_REPORTING_PERIOD = 0x0010, /**< (Deprecated) (Optional) */
    ZCL_METER_SVR_ATTR_PRESET_READING_TIME = 0x0011, /**< PresetReadingTime (Optional) */
    ZCL_METER_SVR_ATTR_VOLUME_PER_REPORT = 0x0012, /**< SummationDeliveredPerReport (Optional) */
    ZCL_METER_SVR_ATTR_FLOW_RESTRICTION = 0x0013, /**< FlowRestriction (Optional) */
    ZCL_METER_SVR_ATTR_SUPPLY_STATUS = 0x0014, /**< Supply Status (Optional) */
    ZCL_METER_SVR_ATTR_INLET_EC_SUMMATION = 0x0015, /**< CurrentInletEnergyCarrierSummation (Optional) */
    ZCL_METER_SVR_ATTR_OUTLET_EC_SUMMATION = 0x0016, /**< CurrentOutletEnergyCarrierSummation (Optional) */
    ZCL_METER_SVR_ATTR_INLET_TEMPERATURE = 0x0017, /**< InletTemperature (Optional) */
    ZCL_METER_SVR_ATTR_OUTLET_TEMPERATURE = 0x0018, /**< OutletTemperature (Optional) */
    ZCL_METER_SVR_ATTR_CONTROL_TEMPERATURE = 0x0019, /**< ControlTemperature (Optional) */
    ZCL_METER_SVR_ATTR_INLET_EC_DEMAND = 0x001a, /**< CurrentInletEnergyCarrierDemand (Optional) */
    ZCL_METER_SVR_ATTR_OUTLET_EC_DEMAND = 0x001b, /**< CurrentOutletEnergyCarrierDemand (Optional) */
    ZCL_METER_SVR_ATTR_PREVIOUS_BLOCK_DELIV = 0x001c, /**< PreviousBlockPeriodConsumptionDelivered (Optional) */
    ZCL_METER_SVR_ATTR_CURBLOCK_CONSUMPTION_RECIEVED = 0x001d, /**< CurrentBlockPeriod ConsumptionReceived (Optional) */
    ZCL_METER_SVR_ATTR_CURBLOCK_RECV = 0x001e, /**< CurrentBlockReceived (Optional) */
    ZCL_METER_SVR_ATTR_DFT_SUM_RECV = 0x001f, /**< DFTSummation Received (Optional) */
    ZCL_METER_SVR_ATTR_ACTREGTIER_DELIV = 0x0020, /**< ActiveRegisterTier Delivered (Optional) */
    ZCL_METER_SVR_ATTR_ACTREGTIER_RECV = 0x0021, /**< ActiveRegisterTier Received (Optional) */
    ZCL_METER_SVR_ATTR_LAST_BLOCK_SWITCH_TIME = 0x0022, /**< LastBlockSwitchTime (Optional) */

    /* Summation TOU Information Set (0x01) */
    ZCL_METER_SVR_ATTR_TIER1_DELIV = 0x0100,
    /**< CurrentTier1SummationDelivered (Optional)
     * For all the tiers, use the ZCL_METER_SVR_ATTR_TIERN_DELIV(tier) macro. */
    ZCL_METER_SVR_ATTR_TIER1_RECV = 0x0101,
    /**< CurrentTier1SummationReceived (Optional)
     * For all the tiers, use the ZCL_METER_SVR_ATTR_TIERN_RECV(tier) macro. */

    /* Meter Status Set (0x02) */
    ZCL_METER_SVR_ATTR_METER_STATUS = 0x0200, /**< Status */
    ZCL_METER_SVR_ATTR_RMN_BATT_LIFE = 0x0201, /**< RemainingBatteryLife (Optional) */
    ZCL_METER_SVR_ATTR_HOURS_IN_OPERATION = 0x0202, /**< HoursInOperation (Optional) */
    ZCL_METER_SVR_ATTR_HOURS_IN_FAULT = 0x0203, /**< HoursInFault (Optional) */
    ZCL_METER_SVR_ATTR_EXTENDED_STATUS = 0x0204, /**< Extended Status (Optional) */
    ZCL_METER_SVR_ATTR_RMN_BATT_DAYS = 0x0205, /**< Remaining BatteryLife in Days (Optional) */
    ZCL_METER_SVR_ATTR_CURMETER_ID = 0x0206, /**< CurrentMeterID (Optional) */
    ZCL_METER_SVR_ATTR_AMBIENT_CONSUMPTION_INDICATOR = 0x0207, /**< AmbientConsumptionIndicator (Optional) */

    /* Formatting Set (0x03) */
    ZCL_METER_SVR_ATTR_UNIT_OF_MEASURE = 0x0300, /**< UnitofMeasure */
    ZCL_METER_SVR_ATTR_MULTIPLIER = 0x0301, /**< Multiplier (Optional) */
    ZCL_METER_SVR_ATTR_DIVISOR = 0x0302, /**< Divisor (Optional) */
    ZCL_METER_SVR_ATTR_SUMMATION_FORMAT = 0x0303, /**< SummationFormatting */
    ZCL_METER_SVR_ATTR_DEMAND_FORMAT = 0x0304, /**< DemandFormatting (Optional) */
    ZCL_METER_SVR_ATTR_HISTORICAL_CONSUMPTION_FORMAT = 0x0305, /**< HistoricalConsumptionFormatting (Optional) */
    ZCL_METER_SVR_ATTR_DEVICE_TYPE = 0x0306, /**< MeteringDeviceType */
    ZCL_METER_SVR_ATTR_SITE_ID = 0x0307, /**< SiteID (Optional) */
    ZCL_METER_SVR_ATTR_SERIAL_NUMBER = 0x0308, /**< MeterSerialNumber (Optional) */
    ZCL_METER_SVR_ATTR_EC_UNIT_OF_MEASURE = 0x0309, /**< EnergyCarrierUnitOfMeasure (Optional) */
    ZCL_METER_SVR_ATTR_EC_SUMMATION_FORMAT = 0x030a, /**< EnergyCarrierSummationFormatting (Optional) */
    ZCL_METER_SVR_ATTR_EC_DEMAND_FORMAT = 0x030b, /**< EnergyCarrierDemandFormatting (Optional) */
    ZCL_METER_SVR_ATTR_TEMP_UNIT_OF_MEASURE = 0x030c, /**< TemperatureUnitOfMeasure (Optional) */
    ZCL_METER_SVR_ATTR_TEMP_FORMAT = 0x030d, /**< TemperatureFormatting (Optional) */
    ZCL_METER_SVR_ATTR_MODULE_SERIAL_NUMBER = 0x030e, /**< ModuleSerialNumber (Optional) */
    ZCL_METER_SVR_ATTR_OPERTRFLBL_DELIV = 0x030f, /**< OperatingTariffLabel Delivered (Optional) */
    ZCL_METER_SVR_ATTR_OPERTRFLBL_RECIEVED = 0x0310, /**< OperatingTariffLabel Received (Optional) */
    ZCL_METER_SVR_ATTR_CUSTOMER_ID_NUMBER = 0x0311, /**< CustomerIDNumber (Optional) */
    ZCL_METER_SVR_ATTR_ALT_UNIT_OF_MEASURE = 0x0312, /**< AlternativeUnitof Measure (Optional) */
    ZCL_METER_SVR_ATTR_ALT_DEMAND_FORMATTING = 0x0313, /**< AlternativeDemandFormatting (Optional) */
    ZCL_METER_SVR_ATTR_ALT_CONSUMPTION_FORMATTING = 0x0314, /**< AlternativeDemandFormatting (Optional) */

    /* Historical Consumption Set (0x04) */
    ZCL_METER_SVR_ATTR_INSTANTANEOUS_DEMAND = 0x0400, /**< InstantaneousDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURDAY_DM_DELIV = 0x0401, /**< CurrentDayConsumptionDelivered (Optional) */
    ZCL_METER_SVR_ATTR_CURDAY_DM_RECV = 0x0402, /**< CurrentDayConsumptionReceived (Optional) */
    ZCL_METER_SVR_ATTR_PRVDAY_DM_DELIV = 0x0403, /**< PreviousDayConsumptionDelivered (Optional) */
    ZCL_METER_SVR_ATTR_PRVDAY_DM_RECV = 0x0404, /**< PreviousDayConsumptionReceived (Optional) */
    ZCL_METER_SVR_ATTR_CURPRTL_DELIV_START = 0x0405, /**< CurrentPartialProfileIntervalStartTimeDelivered (Optional) */
    ZCL_METER_SVR_ATTR_CURPRTL_RECV_START = 0x0406, /**< CurrentPartialProfileIntervalStartTimeReceived (Optional) */
    ZCL_METER_SVR_ATTR_CURPRTL_DELIV = 0x0407, /**< CurrentPartialProfileIntervalValueDelivered (Optional) */
    ZCL_METER_SVR_ATTR_CURPRTL_RECV = 0x0408, /**< CurrentPartialProfileIntervalValueReceived (Optional) */
    ZCL_METER_SVR_ATTR_CURDAY_MAX_PRESSURE = 0x0409, /**< CurrentDayMaxPressure (Optional) */
    ZCL_METER_SVR_ATTR_CURDAY_MIN_PRESSURE = 0x040a, /**< CurrentDayMinPressure (Optional) */
    ZCL_METER_SVR_ATTR_PRVDAY_MAX_PRESSURE = 0x040b, /**< PreviousDayMaxPressure (Optional) */
    ZCL_METER_SVR_ATTR_PRVDAY_MIN_PRESSURE = 0x040c, /**< PreviousDayMinPressure (Optional) */
    ZCL_METER_SVR_ATTR_CURDAY_MAX_DEMAND = 0x040d, /**< CurrentDayMaxDemand (Optional) */
    ZCL_METER_SVR_ATTR_PRVDAY_MAX_DEMAND = 0x040e, /**< PreviousDayMaxDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURMTH_MAX_DEMAND = 0x040f, /**< CurrentMonthMaxDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURYR_MAX_DEMAND = 0x0410, /**< CurrentYearMaxDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURDAY_EC_MAX_DEMAND = 0x0411, /**< CurrentDayMaxEnergyCarrierDemand (Optional) */
    ZCL_METER_SVR_ATTR_PRVDAY_EC_MAX_DEMAND = 0x0412, /**< PreviousDayMaxEnergyCarrierDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURMTH_EC_MAX_DEMAND = 0x0413, /**< CurrentMonthMaxEnergyCarrierDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURMTH_EC_MIN_DEMAND = 0x0414, /**< CurrentMonthMinEnergyCarrierDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURYR_EC_MAX_DEMAND = 0x0415, /**< CurrentYearMaxEnergyCarrierDemand (Optional) */
    ZCL_METER_SVR_ATTR_CURYR_EC_MIN_DEMAND = 0x0416, /**< CurrentYearMinEnergyCarrierDemand (Optional) */

    ZCL_METER_SVR_ATTR_PRVDAY_2_DELIV_CONSUMP = 0x0420,
    /**< PreviousDay2ConsumptionDelivered (Optional)
    * ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(2)
    * For all the previous days, use the ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(prev_day) macro. */
    ZCL_METER_SVR_ATTR_PRVDAY_2_RECV_CONSUMP = 0x0421,
    /**< PreviousDay2ConsumptionReceived (Optional)
    * ZCL_METER_SVR_ATTR_PRVDAY_N_RECV_CONSUMP(2)
    * For all the previous days, use the ZCL_METER_SVR_ATTR_PRVDAY_N_RECV_CONSUMP(prev_day) macro. */

    ZCL_METER_SVR_ATTR_WEEK_0_CONSUMP_DELIV = 0x0430,
    /**< CurrentWeekConsumptionDelivered (Optional) - ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(0) */
    ZCL_METER_SVR_ATTR_WEEK_0_CONSUMP_RECV = 0x0431,
    /**< CurrentWeekConsumptionReceived (Optional) - ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_RECV(0) */
    ZCL_METER_SVR_ATTR_WEEK_1_CONSUMP_DELIV = 0x0432,
    /**< PreviousWeekConsumptionDelivered (Optional) - ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(1) */
    ZCL_METER_SVR_ATTR_WEEK_1_CONSUMP_RECV = 0x0433,
    /**< PreviousWeekConsumptionReceived (Optional) - ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_RECV(1) */
    ZCL_METER_SVR_ATTR_WEEK_2_CONSUMP_DELIV = 0x0434,
    /**< PreviousWeek2ConsumptionDelivered (Optional)
     * ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(2)
     * For all the week consumption delivered, use the ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(prev_week) macro. */
    ZCL_METER_SVR_ATTR_WEEK_2_CONSUMP_RECV = 0x0435,
    /**< PreviousWeek2ConsumptionReceived (Optional)
     * ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_RECV(2)
     * For all the week consumption received, use the ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_RECV(prev_week) macro. */

    ZCL_METER_SVR_ATTR_MONTH_0_CONSUMP_DELIV = 0x0440,
    /**< CurrentMonthConsumptionDelivered (Optional) - ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(0) */
    ZCL_METER_SVR_ATTR_MONTH_0_CONSUMP_RECV = 0x0441,
    /**< CurrentMonthConsumptionReceived (Optional) - ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_RECV(0) */
    ZCL_METER_SVR_ATTR_MONTH_1_CONSUMP_DELIV = 0x0442,
    /**< PreviousMonthConsumptionDelivered (Optional) - ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(1) */
    ZCL_METER_SVR_ATTR_MONTH_1_CONSUMP_RECV = 0x0443,
    /**< PreviousMonthConsumptionReceived (Optional) - ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_RECV(1) */
    ZCL_METER_SVR_ATTR_MONTH_2_CONSUMP_DELIV = 0x0444,
    /**< PreviousMonth2ConsumptionDelivered (Optional)
     * ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(2)
     * For all the month consumption delivered, use the ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(prev_month) macro. */
    ZCL_METER_SVR_ATTR_MONTH_2_CONSUMP_RECV = 0x0445,
    /**< PreviousMonth2ConsumptionReceived (Optional)
     * ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_RECV(2)
     * For all the prev_month consumption received, use the ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_RECV(prev_month) macro. */

    ZCL_METER_SVR_ATTR_HISTORICAL_FREEZE_TIME = 0x045C, /**< Historical Freeze Time (Optional) */

    /* Load Profile Configuration Set (0x05) */
    ZCL_METER_SVR_ATTR_MAX_PERIODS_DELIV = 0x0500, /**< MaxNumberOfPeriodsDelivered (Optional) */

    /* Supply Limit Set (0x06) */
    ZCL_METER_SVR_ATTR_CURDEMAND_DELIV = 0x0600, /**< CurrentDemandDelivered (Optional) */
    ZCL_METER_SVR_ATTR_DEMAND_LIMIT = 0x0601, /**< DemandLimit (Optional) */
    ZCL_METER_SVR_ATTR_DEMAND_INTEGRATION_PERIOD = 0x0602, /**< DemandIntegrationPeriod (Optional) */
    ZCL_METER_SVR_ATTR_DEMAND_SUBINTERVALS = 0x0603, /**< NumberOfDemandSubintervals (Optional) */
    ZCL_METER_SVR_ATTR_SUPPLY_LIMIT_ARM_DURATION = 0x0604, /**< DemandLimitArmDuration (Optional) */
    ZCL_METER_SVR_ATTR_LOAD_LIMIT_SUPPLY_STATE = 0x0605, /**< LoadLimitSupplyState (Optional) */
    ZCL_METER_SVR_ATTR_LOAD_LIMIT_COUNTER = 0x0606, /**< LoadLimitCounter (Optional) */
    ZCL_METER_SVR_ATTR_SUPPLY_TAMPER_STATE = 0x0607, /**< SupplyTamperState (Optional) */
    ZCL_METER_SVR_ATTR_SUPPLY_DEPLETION_STATE = 0x0608, /**< SupplyDepletionState (Optional) */
    ZCL_METER_SVR_ATTR_SUPPLY_UNCONTROLLED_FLOW_STATE = 0x0609, /**< SupplyUncontrolled FlowState (Optional) */

    /* Block Information Set (Delivered) (0x07) */
    ZCL_METER_SVR_ATTR_NO_TIER_BLOCK1_DELIV = 0x0700,
    /**< CurrentNoTierBlock1SummationDelivered (Optional)
     * ZCL_METER_SVR_ATTR_NO_TIER_BLOCKN_DELIV(1)
     * For all CurrentNoTierBlockNSummationDelivered, use the ZCL_METER_SVR_ATTR_NO_TIER_BLOCKN_DELIV(block) macro. */
    ZCL_METER_SVR_ATTR_TIER1_BLOCK1_DELIV = 0x0710,
    /**< CurrentTier1Block1SummationDelivered (Optional)
     * ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(1,1)
     * For all CurrentTierNBlockNSummationDelivered, use the ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(tier, block) macro. */

    /* Alarms Set (0x08) */
    ZCL_METER_SVR_ATTR_GENERIC_ALARM_MASK = 0x0800, /**< Generic Alarm Mask */
    ZCL_METER_SVR_ATTR_ELECTRICITY_ALARM_MASK = 0x0801, /**< Electricity Alarm Mask */
    ZCL_METER_SVR_ATTR_FLOW_PRESSURE_ALARM_MASK = 0x0802, /**< Generic Flow/Pressure Alarm Mask */
    ZCL_METER_SVR_ATTR_WATER_ALARM_MASK = 0x0803, /**< Water Specific Alarm Mask */
    ZCL_METER_SVR_ATTR_HEAT_COOLING_ALARM_MASK = 0x0804, /**< Heat and Cooling Specific Alarm Mask */
    ZCL_METER_SVR_ATTR_GAS_ALARM_MASK = 0x0805, /**< Gas Specific AlarmMask */
    ZCL_METER_SVR_ATTR_EXTENDED_GENERIC_ALARM_MASK = 0x0806, /**< ExtendedGenericAlarmMask */
    ZCL_METER_SVR_ATTR_MANUFACTURER_ALARM_MASK = 0x0807, /**< ManufacturerAlarmMask */

    /* Block Information Set (Received) (0x09) */
    ZCL_METER_SVR_ATTR_NO_TIER_BLOCK1_RECV = 0x0900,
    /**< CurrentNoTierBlock1SummationReceived (Optional)
     * ZCL_METER_SVR_ATTR_NO_TIER_BLOCKN_RECV(1)
     * For all CurrentNoTierBlockNSummationReceived, use the ZCL_METER_SVR_ATTR_NO_TIER_BLOCKN_RECV(block) macro. */
    ZCL_METER_SVR_ATTR_TIER1_BLOCK1_RECV = 0x0910,
    /**< CurrentTier1Block1SummationReceived (Optional)
     * ZCL_METER_SVR_ATTR_TIERN_BLOCKN_RECV(1,1)
     * For all CurrentTierNBlockNSummationReceived, use the ZCL_METER_SVR_ATTR_TIERN_BLOCKN_RECV(tier, block) macro. */

    /* Meter Billing Set (0x0a) */
    ZCL_METER_SVR_ATTR_BTD_DELIV = 0x0a00, /**< BillToDateDelivered (Optional) */
    ZCL_METER_SVR_ATTR_BTD_TIMESTAMP_DELIV = 0x0a01, /**< BillToDateTimeStampDelivered (Optional) */
    ZCL_METER_SVR_ATTR_PROJ_BILL_DELIV = 0x0a02, /**< ProjectedBillDelivered (Optional) */
    ZCL_METER_SVR_ATTR_PROJ_BILL_TIMESTAMP_DELIV = 0x0a03, /**< ProjectedBillTimeStampDelivered (Optional) */
    ZCL_METER_SVR_ATTR_BILL_DELIV_TRAILING_DIGIT = 0x0a04, /**< BillDeliveredTrailingDigit (Optional) */
    ZCL_METER_SVR_ATTR_BTD_RECV = 0x0a10, /**< BillToDateReceived (Optional) */
    ZCL_METER_SVR_ATTR_BTD_TIMESTAMP_RECV = 0x0a11, /**< BillToDateTimeStampReceived (Optional) */
    ZCL_METER_SVR_ATTR_PROJ_BILL_RECV = 0x0a12, /**< ProjectedBillReceived (Optional) */
    ZCL_METER_SVR_ATTR_PROJ_BILL_TIMESTAMP_RECV = 0x0a13, /**< ProjectedBillTimeStampReceived (Optional) */
    ZCL_METER_SVR_ATTR_BILL_RECV_TRAILING_DIGIT = 0x0a14, /**< ProjectedBillTimeStampReceived (Optional) */

    /* Supply Control Set (0x0B) */
    ZCL_METER_SVR_ATTR_PROP_CHG_SUPPLY_IMPL_TIME = 0x0b00, /**< ProposedChangeSupply ImplementationTime (Optional) */
    ZCL_METER_SVR_ATTR_PROP_CHG_SUPPLY_STATUS = 0x0b01, /**< ProposedChange SupplyStatus (Optional) */
    ZCL_METER_SVR_ATTR_UNCTLFLOW_THRESHOLD = 0x0b10, /**< Uncontrolled Flow Threshold (Optional) */
    ZCL_METER_SVR_ATTR_UNCTLFLOW_UNIT_OF_MEASURE = 0x0b11, /**< Uncontrolled Flow Threshold Unit of Measure (Optional) */
    ZCL_METER_SVR_ATTR_UNCTLFLOW_MULTIPLIER = 0x0b12, /**< Uncontrolled Flow Multiplier (Optional) */
    ZCL_METER_SVR_ATTR_UNCTLFLOW_DIVISOR = 0x0b13, /**< Uncontrolled Flow Divisor (Optional) */
    ZCL_METER_SVR_ATTR_FLOW_STABILISATION_PERIOD = 0x0b14, /**< Flow Stabilisation Period (Optional) */
    ZCL_METER_SVR_ATTR_FLOW_MEASUREMENT_PERIOD = 0x0b15, /**< Flow Measurement Period (Optional) */

    /* Alternative Historical Consumption (0x0C) */
    ZCL_METER_SVR_ATTR_ALT_INSTANTANEOUS_DEMAND = 0x0c00 /**< AlternativeInstantaneousDemand (Optional) */
        /* ! Remaining enum values or macros not supported */
};

/* Simple Metering Time of Use Information Attributes */

/* Tiers start at 1 and go to a max of 48.
 * They should have started at an index of 0, but oh well */
#define ZCL_METER_SVR_ATTR_TIERN_MAX                                48U
#define ZCL_METER_SVR_ATTR_TIERN_DELIV(tier)                        (0x0100U + (2U * ((tier) - 1U)))
#define ZCL_METER_SVR_ATTR_TIERN_RECV(tier)                         (0x0101U + (2U * ((tier) - 1U)))

/* Simple Metering Block Information Attributes (Delivered) */
#define ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(tier, block)          (0x0700U + ((block) - 1U) + (0x10U * (tier)))
#define ZCL_METER_SVR_ATTR_NO_TIER_BLOCKN_DELIV(block)              ZCL_METER_SVR_ATTR_TIERN_BLOCKN_DELIV(0U, (block))

/* Simple Metering Block Information Attributes (Received) */
#define ZCL_METER_SVR_ATTR_TIERN_BLOCKN_RECV(tier, block)           (0x0900U + ((block) - 1U) + (0x10U * (tier)))
#define ZCL_METER_SVR_ATTR_NO_TIER_BLOCKN_RECV(block)               ZCL_METER_SVR_ATTR_TIERN_BLOCKN_RECV(0U, block)

/* Simple Metering ESP Historical Attributes */
#define ZCL_METER_SVR_ATTR_PRVDAY_N_DELIV_CONSUMP(prev_day)         (0x0420U + (2U * ((prev_day) - 2U)))
#define ZCL_METER_SVR_ATTR_PRVDAY_N_RECV_CONSUMP(prev_day)          (0x0421U + (2U * ((prev_day) - 2U)))

#define ZCL_METER_SVR_ATTR_WEEK_FIRST_CONSUMP_DELIV                 0U
#define ZCL_METER_SVR_ATTR_WEEK_MAX_CONSUMP_DELIV                   6U /* less than, i.e. 0..5 */
#define ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_DELIV(prev_week)          (0x0430U + (2U * (prev_week)))
#define ZCL_METER_SVR_ATTR_WEEK_N_CONSUMP_RECV(prev_week)           (0x0431U + (2U * (prev_week)))
#define ZCL_METER_SVR_ATTR_MONTH_FIRST_CONSUMP_DELIV                0U
#define ZCL_METER_SVR_ATTR_MONTH_MAX_CONSUMP_DELIV                  14U /* less than, i.e. 0..13 */
#define ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_DELIV(prev_month)        (0x0440U + (2U * (prev_month)))
#define ZCL_METER_SVR_ATTR_MONTH_N_CONSUMP_RECV(prev_month)         (0x0441U + (2U * (prev_month)))

enum ZbZclMeterCliAttrT {
    /* Notification Set (0x00) */
    /* Notification Flags (ZCL_METER_CLI_NOTIF_FLG_) */
    ZCL_METER_CLI_ATTR_NOTIF_FLG_1 = 0x0000,
    ZCL_METER_CLI_ATTR_NOTIF_FLG_2, /* 0x0001 */
    ZCL_METER_CLI_ATTR_NOTIF_FLG_3, /* 0x0002 */
    ZCL_METER_CLI_ATTR_NOTIF_FLG_4, /* 0x0003 */
    ZCL_METER_CLI_ATTR_NOTIF_FLG_5, /* 0x0004 */
    ZCL_METER_CLI_ATTR_NOTIF_FLG_6, /* 0x0005 */
    ZCL_METER_CLI_ATTR_NOTIF_FLG_7, /* 0x0006 */
    ZCL_METER_CLI_ATTR_NOTIF_FLG_8 /* 0x0007 */
};

/* ZCL_METER_CLI_ATTR_NOTIF_FLG_ */
#define ZCL_METER_CLI_NOTIF_FLG_NEW_OTA_FW                      0x00000001U /* bit  0 */
#define ZCL_METER_CLI_NOTIF_FLG_CBKE_UPDATE_REQ                 0x00000002U /* bit  1 */
#define ZCL_METER_CLI_NOTIF_FLG_TIME_SYNC                       0x00000004U /* bit  2 */
/* Reserved - 0x00000008U */
#define ZCL_METER_CLI_NOTIF_FLG_STAY_AWAKE_HAN                  0x00000010U /* bit  4 */
#define ZCL_METER_CLI_NOTIF_FLG_STAY_AWAKE_WAN                  0x00000020U /* bit  5 */
#define ZCL_METER_CLI_NOTIF_FLG_PUSH_HIST_METER_MASK            0x000001C0U /* bits 6-8 */
#define ZCL_METER_CLI_NOTIF_FLG_PUSH_HIST_PREPAY_SET            0x00000E00U /* bits 9-11 */
#define ZCL_METER_CLI_NOTIF_FLG_PUSH_STATIC_BASIC               0x00001000U /* bit 12 */
#define ZCL_METER_CLI_NOTIF_FLG_PUSH_STATIC_METER               0x00002000U /* bit 13 */
#define ZCL_METER_CLI_NOTIF_FLG_PUSH_STATIC_PREPAY              0x00004000U /* bit 14 */
#define ZCL_METER_CLI_NOTIF_FLG_NETWORK_KEY_ACTIVE              0x00008000U /* bit 15 */
#define ZCL_METER_CLI_NOTIF_FLG_DISPLAY_MESSAGE                 0x00010000U /* bit 16 */
#define ZCL_METER_CLI_NOTIF_FLG_CANCEL_ALL_MESSAGES             0x00020000U /* bit 17 */
#define ZCL_METER_CLI_NOTIF_FLG_CHANGE_SUPPLY                   0x00040000U /* bit 18 */
#define ZCL_METER_CLI_NOTIF_FLG_LOCAL_CHANGE_SUPPLY             0x00080000U /* bit 19 */
#define ZCL_METER_CLI_NOTIF_FLG_SET_UNCONTROLLED_FLOW_THRESH    0x00100000U /* bit 20 */
#define ZCL_METER_CLI_NOTIF_FLG_TUNNEL_MESSAGE_PEND             0x00200000U /* bit 21 */
#define ZCL_METER_CLI_NOTIF_FLG_GET_SNAPSHOT                    0x00400000U /* bit 22 */
#define ZCL_METER_CLI_NOTIF_FLG_GET_SAMPLED_DATA                0x00800000U /* bit 23 */
#define ZCL_METER_CLI_NOTIF_FLG_NEW_SUBGHZ_CHANNEL_MASKS        0x01000000U /* bit 24 */
#define ZCL_METER_CLI_NOTIF_FLG_ENERGY_SCAN_PEND                0x02000000U /* bit 25 */
#define ZCL_METER_CLI_NOTIF_FLG_CHANNEL_CHANGE_PEND             0x04000000U /* bit 26 */

/* Metering Status flags */
#define ZCL_METER_STATUS_CHECK_METER                0x01U
#define ZCL_METER_STATUS_LOW_BATTERY                0x02U
#define ZCL_METER_STATUS_TAMPER_DETECT              0x04U
#define ZCL_METER_STATUS_POWER_FAILURE              0x08U
#define ZCL_METER_STATUS_PIPE_EMPTY                 0x08U
#define ZCL_METER_STATUS_TEMPERATURE_SENSOR         0x08U
#define ZCL_METER_STATUS_POWER_QUALITY              0x10U
#define ZCL_METER_STATUS_LOW_PRESSURE               0x10U
#define ZCL_METER_STATUS_BURST_DETECT               0x10U
#define ZCL_METER_STATUS_LEAK_DETECT                0x20U
#define ZCL_METER_STATUS_SERVICE_DISCONNECT         0x40U
#define ZCL_METER_STATUS_REVERSE_FLOW               0x80U
#define ZCL_METER_STATUS_FLOW_SENSOR                0x80U

#define ZCL_METER_FORMAT_FRACTIONAL                 0x07U
#define ZCL_METER_FORMAT_INTEGER                    0x78U
#define ZCL_METER_FORMAT_SUPPRESS_LEADING_ZERO      0x80U
#define ZCL_METER_FORMAT_OFFSET_FRACTIONAL          0U
#define ZCL_METER_FORMAT_OFFSET_INTEGER             3U

/* Metering Units of Measure enumeration */
enum ZbZclMeterUnitsT {
    ZCL_METER_UNITS_BINARY_KWH = 0x00,
    ZCL_METER_UNITS_BINARY_CUBIC_METERS = 0x01,
    ZCL_METER_UNITS_BINARY_CUBIC_FEET = 0x02,
    ZCL_METER_UNITS_BINARY_CCF = 0x03,
    ZCL_METER_UNITS_BINARY_US_GALLON = 0x04,
    ZCL_METER_UNITS_BINARY_IMPERIAL_GALLON = 0x05,
    ZCL_METER_UNITS_BINARY_BTU = 0x06,
    ZCL_METER_UNITS_BINARY_LITERS = 0x07,
    ZCL_METER_UNITS_BINARY_RELATIVE_KPA = 0x08,
    ZCL_METER_UNITS_BINARY_ABSOLUTE_KPA = 0x09,
    ZCL_METER_UNITS_BINARY_MCF = 0x0a, /* SE 1.1 */
    ZCL_METER_UNITS_BINARY_UNITLE = 0x0b, /* SE 1.1 */
    ZCL_METER_UNITS_BINARY_MEGA_JOULE = 0x0c, /* SE 1.1 */
    ZCL_METER_UNITS_BINARY_KVAR = 0x0d, /* SE 1.2a */

    ZCL_METER_UNITS_BCD_KWH = 0x80,
    ZCL_METER_UNITS_BCD_CUBIC_METERS = 0x81,
    ZCL_METER_UNITS_BCD_CUBIC_FEET = 0x82,
    ZCL_METER_UNITS_BCD_CCF = 0x83,
    ZCL_METER_UNITS_BCD_US_GALLON = 0x84,
    ZCL_METER_UNITS_BCD_IMPERIAL_GALLON = 0x85,
    ZCL_METER_UNITS_BCD_BTU = 0x86,
    ZCL_METER_UNITS_BCD_LITERS = 0x87,
    ZCL_METER_UNITS_BCD_RELATIVE_KPA = 0x88,
    ZCL_METER_UNITS_BCD_ABSOLUTE_KPA = 0x89,
    ZCL_METER_UNITS_BCD_MCF = 0x8a, /* SE 1.1 */
    ZCL_METER_UNITS_BCD_UNITLE = 0x8b, /* SE 1.1 */
    ZCL_METER_UNITS_BCD_MEGA_JOULE = 0x8c, /* SE 1.1 */
    ZCL_METER_UNITS_BCD_KVAR = 0x8d /* SE 1.2a */
};

/* Metering Device Type enumerations (ZCL_METER_SVR_ATTR_DEVICE_TYPE) */
enum ZbZclMeterTypeT {
    ZCL_METER_TYPE_ELECTRIC = 0x00,
    ZCL_METER_TYPE_GAS = 0x01,
    ZCL_METER_TYPE_WATER = 0x02,
#if 0 /* Deprecated as of SE 1.1 */
    ZCL_METER_TYPE_THERMAL = 0x03,
#endif
    ZCL_METER_TYPE_PRESSURE = 0x04,
    ZCL_METER_TYPE_HEAT = 0x05,
    ZCL_METER_TYPE_COOLING = 0x06,

    ZCL_METER_TYPE_END_USE_METER = 0x07, /* SE 1.1b */
    ZCL_METER_TYPE_PV_GEN = 0x08, /* SE 1.1b */
    ZCL_METER_TYPE_WIND_GEN = 0x09, /* SE 1.1b */
    ZCL_METER_TYPE_WATER_GEN = 0x0a, /* SE 1.1b */
    ZCL_METER_TYPE_MICRO_GEN = 0x0b, /* SE 1.1b */
    ZCL_METER_TYPE_SOLAR_HW = 0x0c, /* SE 1.1b */
    ZCL_METER_TYPE_ELECTRIC_PHASE_1 = 0x0d, /* SE 1.1b */
    ZCL_METER_TYPE_ELECTRIC_PHASE_2 = 0x0e, /* SE 1.1b */
    ZCL_METER_TYPE_ELECTRIC_PHASE_3 = 0x0f, /* SE 1.1b */

    ZCL_METER_TYPE_MIRR_ELECTRIC = 0x7f,
    ZCL_METER_TYPE_MIRR_GAS = 0x80,
    ZCL_METER_TYPE_MIRR_WATER = 0x81,
#if 0 /* Deprecated as of SE 1.1 */
    ZCL_METER_TYPE_MIRR_THERMAL = 0x82,
#endif
    ZCL_METER_TYPE_MIRR_PRESSURE = 0x83,
    ZCL_METER_TYPE_MIRR_HEAT = 0x84,
    ZCL_METER_TYPE_MIRR_COOLING = 0x85,

    ZCL_METER_TYPE_MIRR_END_USE_METER = 0x86, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_PV_GEN = 0x87, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_WIND_GEN = 0x88, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_WATER_GEN = 0x89, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_MICRO_GEN = 0x8a, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_SOLAR_HW = 0x8b, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_ELECPHS_1 = 0x8c, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_ELECPHS_2 = 0x8d, /* SE 1.1b */
    ZCL_METER_TYPE_MIRR_ELECPHS_3 = 0x8e /* SE 1.1b */
};

/*lint -save -e849 [ !MISRA - multiple string with same enum value. ] */
/* In the infinite wisdom of zigbee, they use the same enumeration values
 *  for different meter types (e.g. alarm code 0x03 means power failure for
 *  electric meter , but means pipe empty for water meter).
 */
/* Metering Status Attribute bit locations */
enum ZbZclMeterAlarmT {
    /* Simple Metering alarm codes */
    ZCL_METER_ALARM_CHECK_METER = 0x00,
    ZCL_METER_ALARM_LOW_BATTERY = 0x01,
    ZCL_METER_ALARM_TAMPER_DETECT = 0x02,
    ZCL_METER_ALARM_POWER_FAILURE = 0x03, /* Electricity alarm only */
    ZCL_METER_ALARM_PIPE_EMPTY = 0x03, /* Water alarm only.  */
    ZCL_METER_ALARM_TEMPERATURE_SENSOR = 0x03, /* Heating/Cooling alarm only */
    ZCL_METER_ALARM_POWER_QUALITY = 0x04, /* Electricity alarm only */
    ZCL_METER_ALARM_LOW_PRESSURE = 0x04, /* Gas and Water alarms only */
    ZCL_METER_ALARM_BURST_DETECT = 0x04, /* Heating/Cooling alarm only */
    ZCL_METER_ALARM_LEAK_DETECT = 0x05,
    ZCL_METER_ALARM_SERVICE_DISCONNECT = 0x06,
    ZCL_METER_ALARM_REVERSE_FLOW = 0x07, /* Gas and Water alarms only */
    ZCL_METER_ALARM_FLOW_SENSOR = 0x07, /* Heating/Cooling alarm only */

    /* Simple Metering Electricity alarm codes */
    ZCL_METER_ALARM_LOW_VOLTAGE_L1 = 0x10,
    ZCL_METER_ALARM_HIGH_VOLTAGE_L1 = 0x11,
    ZCL_METER_ALARM_LOW_VOLTAGE_L2 = 0x12,
    ZCL_METER_ALARM_HIGH_VOLTAGE_L2 = 0x13,
    ZCL_METER_ALARM_LOW_VOLTAGE_L3 = 0x14,
    ZCL_METER_ALARM_HIGH_VOLTAGE_L4 = 0x15,
    ZCL_METER_ALARM_OVER_CURRENT_L1 = 0x16,
    ZCL_METER_ALARM_OVER_CURRENT_L2 = 0x17,
    ZCL_METER_ALARM_OVER_CURRENT_L3 = 0x18,
    ZCL_METER_ALARM_FREQ_LOW_L1 = 0x19,
    ZCL_METER_ALARM_FREQ_HIGH_L1 = 0x1a,
    ZCL_METER_ALARM_FREQ_LOW_L2 = 0x1b,
    ZCL_METER_ALARM_FREQ_HIGH_L2 = 0x1c,
    ZCL_METER_ALARM_FREQ_LOW_L3 = 0x1d,
    ZCL_METER_ALARM_FREQ_HIGH_L3 = 0x1e,
    ZCL_METER_ALARM_GROUND_FAULT = 0x1f,
    ZCL_METER_ALARM_ELECTRIC_TAMPER_DETECT = 0x20,

    /* Simple Metering Pressure/Flow alarm codes */
    ZCL_METER_ALARM_PRESSURE_BURST_DETECT = 0x30,
    ZCL_METER_ALARM_PRESSURE_TOO_LOW = 0x31,
    ZCL_METER_ALARM_PRESSURE_TOO_HIGH = 0x32,
    ZCL_METER_ALARM_FLOW_COMM_ERROR = 0x33,
    ZCL_METER_ALARM_FLOW_MEASUREMENT_FAULT = 0x34,
    ZCL_METER_ALARM_FLOW_REVERSE = 0x35,
    ZCL_METER_ALARM_FLOW_AIR_DETECT = 0x36,
    ZCL_METER_ALARM_FLOW_PIPE_EMPTY = 0x37,

    /* Simple Metering Heat and Cooling alarm codes */
    ZCL_METER_ALARM_INLET_TEMPERATURE_SENSOR = 0x50,
    ZCL_METER_ALARM_OUTLET_TEMPERATURE_SENSOR = 0x51
};
/*lint -restore */

/* Metering Profile intervals */
enum ZbZclMeterProfileIntervalT {
    ZCL_METER_PRFL_PERIOD_DAILY = 0x00,
    ZCL_METER_PRFL_PERIOD_HOURLY = 0x01,
    ZCL_METER_PRFL_PERIOD_30MIN = 0x02,
    ZCL_METER_PRFL_PERIOD_15MIN = 0x03,
    ZCL_METER_PRFL_PERIOD_10MIN = 0x04,
    ZCL_METER_PRFL_PERIOD_450SEC = 0x05,
    ZCL_METER_PRFL_PERIOD_300SEC = 0x06,
    ZCL_METER_PRFL_PERIOD_150SEC = 0x07
};

/* Metering Get Profile Response Status */
enum ZbZclMeterGetProfileStatusT {
    ZCL_METER_PRFL_STATUS_SUCCESS = 0x00,
    ZCL_METER_PRFL_STATUS_CHAN_UNDEFINED = 0x01,
    ZCL_METER_PRFL_STATUS_CHAN_UNSUPPORTED = 0x02,
    ZCL_METER_PRFL_STATUS_INVALID_END_TIME = 0x03,
    ZCL_METER_PRFL_STATUS_TOO_MANY_INTERVALS = 0x04,
    ZCL_METER_PRFL_STATUS_NO_INTERVALS = 0x05
};

/* Metering Server Generated Commands */
enum ZbZclMeterServerCommandsT {
    ZCL_METER_SVR_CMD_GET_PROFILE_RESPONSE = 0x00,
    ZCL_METER_SVR_CMD_REQUEST_MIRROR = 0x01,
    ZCL_METER_SVR_CMD_REMOVE_MIRROR = 0x02,
    ZCL_METER_SVR_CMD_FAST_POLL_RESPONSE = 0x03,
    ZCL_METER_SVR_CMD_SCHEDULE_SNAPSHOT_RESPONSE = 0x04,
    ZCL_METER_SVR_CMD_TAKE_SNAPSHOT_RESPONSE = 0x05,
    ZCL_METER_SVR_CMD_PUBLISH_SNAPSHOT = 0x06,
    ZCL_METER_SVR_CMD_GET_SAMPLED_DATA_RESPONSE = 0x07,
    ZCL_METER_SVR_CMD_CONFIGURE_MIRROR = 0x08,
    ZCL_METER_SVR_CMD_CONFIGURE_NOTIFICATION_SCHEME = 0x09,
    ZCL_METER_SVR_CMD_CONFIGURE_NOTIFICATION_FLAG = 0x0a,
    ZCL_METER_SVR_CMD_GET_NOTIFIED_MESSAGE = 0x0b,
    ZCL_METER_SVR_CMD_SUPPLY_STATUS_RESPONSE = 0x0c,
    ZCL_METER_SVR_CMD_START_SAMPLING_RESPONSE_RESERVED = 0x0d
};

/* Metering Client Generated Commands */
enum ZbZclMeterClientCommandsT {
    ZCL_METER_CLI_CMD_GET_PROFILE = 0x00,
    ZCL_METER_CLI_CMD_REQUEST_MIRROR_RESPONSE = 0x01,
    ZCL_METER_CLI_CMD_MIRROR_REMOVED = 0x02,
    ZCL_METER_CLI_CMD_REQUEST_FAST_POLL_MODE = 0x03,
    ZCL_METER_CLI_CMD_SCHEDULE_SNAPSHOT = 0x04,
    ZCL_METER_CLI_CMD_TAKE_SNAPSHOT = 0x05,
    ZCL_METER_CLI_CMD_GET_SNAPSHOT = 0x06,
    ZCL_METER_CLI_CMD_START_SAMPLING = 0x07,
    ZCL_METER_CLI_CMD_GET_SAMPLED_DATA = 0x08,
    ZCL_METER_CLI_CMD_MIRROR_REPORT_ATTRIBUTE_RESPONSE = 0x09,
    ZCL_METER_CLI_CMD_RESET_LOADLIMIT_COUNTER = 0x0a,
    ZCL_METER_CLI_CMD_CHANGE_SUPPLY = 0x0b,
    ZCL_METER_CLI_CMD_LOCAL_CHANGE_SUPPLY = 0x0c,
    ZCL_METER_CLI_CMD_SET_SUPPLY_STATUS = 0x0d,
    ZCL_METER_CLI_CMD_SET_UNCONTROLLED_FLOW_THRESHOLD = 0x0e
};

/* Metering Sample Type Enumerations. These are the same as Interval Channel Values */
enum ZbZclMeterSampleTypeT {
    ZCL_METER_SAMPLE_TYPE_CONSUMP_DELIV = 0x00,
    ZCL_METER_SAMPLE_TYPE_CONSUMP_RECV, /* 0x01 */
    ZCL_METER_SAMPLE_TYPE_REACTIVE_CONSUMP_DELIV, /* 0x02 */
    ZCL_METER_SAMPLE_TYPE_REACTIVE_CONSUMP_RECV, /* 0x03 */
    ZCL_METER_SAMPLE_TYPE_INSTANTANEOUS_DEMAND /* 0x04 */
};

#if 0 /* not used */
struct ZbZclMeterSampleT {
    unsigned long long sumDelivered;
    unsigned long long sumReceived;
    unsigned long long demandDelivered;
    unsigned long long demandReceived;
    signed char powerFactor;
    int currentTier;
    int currentBlock;
};
#endif

/** Get Profile command structure */
struct ZbZclMeterClientGetProfileReqT {
    enum ZbZclMeterSampleTypeT interval_channel; /**< Interval Channel */
    uint32_t end_time; /**< End Time */
    uint8_t number_of_periods; /**< NumberOfPeriods */
};

/** Get Profile Response command structure */
struct ZbZclMeterServerGetProfileRspT {
    uint32_t end_time; /**< End Time */
    enum ZbZclMeterGetProfileStatusT status; /**< Status */
    uint8_t profile_interval_period; /**< ProfileIntervalPeriod */
    uint8_t number_of_periods; /**< NumberOfPeriodsDelivered */
    uint8_t *profile_data; /**< Profile buffer */
    unsigned int profile_length; /**< Profile buffer length */
};

/** Get Sampled Data command structure */
struct ZbZclMeterClientGetSampledDataReqT {
    uint16_t sample_id; /**< SampleID */
    uint32_t earliest_sample_time; /**< EarliestSampleTime */
    enum ZbZclMeterSampleTypeT sample_type; /**< SampleType */
    uint16_t number_of_samples; /**< NumberOfSamples */
};

/** Get Sampled Data Response command structure */
struct ZbZclMeterServerGetSampledDataRspT {
    uint16_t sample_id; /**< SampleID */
    uint32_t sample_start_time; /**< SampleStart Time */
    enum ZbZclMeterSampleTypeT sample_type; /**< SampleType */
    uint16_t sample_request_interval; /**< SampleRequest Interval */
    uint16_t number_of_samples; /**< NumberOfSamples */
    uint8_t *sample_data; /**< Sampled Data buffer */
    unsigned int sample_length; /**< Sampled Data buffer length */
};

enum ZbZclMeterSupplyStatusT {
    ZCL_METER_SUPPLY_STATUS_OFF = 0x00,
    ZCL_METER_SUPPLY_STATUS_OFF_ARMED = 0x01,
    ZCL_METER_SUPPLY_STATUS_ON = 0x02
};

/** Metering Local Change Supply command structure */
struct ZbZclMeterClientLocalChangeSupplyReqT {
    enum ZbZclMeterSupplyStatusT prop_supply_status; /**< Proposed Supply Status */
};

/** Metering Server callbacks configuration */
struct ZbZclMeterServerCallbacksT {
    enum ZclStatusCodeT (*get_profile)(struct ZbZclClusterT *cluster, void *arg,
        struct ZbZclMeterClientGetProfileReqT *req, struct ZbZclAddrInfoT *srcInfo);
    /**< Configure callback to handle ZCL_METER_CLI_CMD_GET_PROFILE.
     * In handling of get_profile(), the application should call
     * ZbZclMeterServerSendGetProfileRsp to send the response if successful.
     * ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error.
     */

    enum ZclStatusCodeT (*get_sampled_data)(struct ZbZclClusterT *cluster, void *arg,
        struct ZbZclMeterClientGetSampledDataReqT *req, struct ZbZclAddrInfoT *srcInfo);
    /**< Configure callback to handle ZCL_METER_CLI_CMD_GET_SAMPLED_DATA.
     * In handling of get_sampled_data(), the application should call
     * ZbZclMeterServerSendGetSampledDataRsp to send the response if successful.
     * ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error.
     */

    enum ZclStatusCodeT (*local_change_supply)(struct ZbZclClusterT *cluster, void *arg,
        struct ZbZclMeterClientLocalChangeSupplyReqT *req, struct ZbZclAddrInfoT *srcInfo);
    /**< Configure callback to handle ZCL_METER_CLI_CMD_LOCAL_CHANGE_SUPPLY.
     * ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error.
     */

    uint16_t (*request_mirror)(void *arg, struct ZbZclClusterT *cluster,
        struct ZbZclAddrInfoT *srcInfo, struct ZbApsdeDataIndT *dataIndPtr);
    /**< Configure callback to handle ZCL_METER_CLI_CMD_REQUEST_MIRROR_RESPONSE command.
     * Callback will register an endpoint for the mirrored metering cluster,
     * and return the endpoint ID or 0xFFFF on error.
     */

    uint16_t (*remove_mirror)(void *arg, struct ZbZclClusterT *cluster,
        struct ZbZclAddrInfoT *srcInfo, struct ZbApsdeDataIndT *dataIndPtr);
    /**< Configure callback to handle ZCL_METER_CLI_CMD_MIRROR_REMOVED command.
     * Callback will register an endpoint for the mirrored metering cluster,
     * and return the endpoint ID or 0xFFFF on error.
     */

    enum ZclStatusCodeT (*optional)(struct ZbZclClusterT *cluster,
        struct ZbZclHeaderT *zclHdrPtr, struct ZbApsdeDataIndT *dataIndPtr);
    /**< Optional commands not parsed into a struct or specific callback. If this is NULL,
     * the cluster will return a Default Response with status of ZCL_STATUS_UNSUPP_CLUSTER_COMMAND.
     * ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error.
     */
};

/**
 * Create a new instance of the Metering Server cluster
 * After initialization, ZbZclClusterSetCallbackArg is called with 'arg' to configure the application's callback argument
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @param callbacks Structure containing any callback function pointers for this cluster
 * @param arg Pointer to application data that will later be provided back to the callback functions when invoked
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclMeterServerAlloc(struct ZigBeeT *zb, uint8_t endpoint,
    struct ZbZclMeterServerCallbacksT *callbacks, void *arg);

/**
 * Convert the profile interval period enumerated value to a time in seconds
 * @param profile_interval_id Zigbee stack instance
 * @return Converted time in seconds or -1 on error
 */
int ZbZclMeterGetProfileIntervalPeriod(uint8_t profile_interval_id);

/**
 * Send a Get Profile Response command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for response, including sequence number and tx options
 * @param rsp Get Profile Response command structure
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclMeterServerSendGetProfileRsp(struct ZbZclClusterT *cluster,
    struct ZbZclAddrInfoT *dst, struct ZbZclMeterServerGetProfileRspT *rsp);

/**
 * Convert an array of 24-bit integers to the Zigbee frame format
 * @param sample_data Converted data for Zigbee frame
 * @param max_len Maximum length
 * @param samples Array of 24-bit integers to convert
 * @param num_samples Number of integers to convert
 * @return Returns the number of octets written to sample_data or -1 on error
 */
int ZbZclMeterFormSampledData(uint8_t *sample_data, unsigned int max_len, uint32_t *samples, uint16_t num_samples);

/**
 * Send a Get Sampled Data Response command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for response, including sequence number and tx options
 * @param rsp Get Sampled Data Response command structure
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
enum ZclStatusCodeT ZbZclMeterServerSendGetSampledDataRsp(struct ZbZclClusterT *cluster,
    struct ZbZclAddrInfoT *dst, struct ZbZclMeterServerGetSampledDataRspT *rsp);

/** Metering Server Mirror Functions */

/**
 * Create a new instance of the Metering Server Mirror cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @param mirrorAddr Address of the Server Mirror
 * @param mirrorEndpoint Endpoint on which to create Mirror cluster
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclMeterServerMirrorAlloc(struct ZigBeeT *zb, uint8_t endpoint,
    uint64_t mirrorAddr, uint8_t mirrorEndpt);

/**
 * Configure an endpoint to mirror to a destination endpoint
 * @param cluster Cluster instance from which to send this command
 * @param srcExtAddr Source address from where reports originate
 * @param dstEndpoint Destination endpoint to where the report is mirrored
 * @return Void
 */
void ZbZclMeterServerMirrorConfig(struct ZbZclClusterT *cluster, uint64_t srcExtAddr, uint8_t dstEndpoint);

/* Metering Client */

/** Metering Client callbacks configuration */
struct ZbZclMeterClientCallbacksT {
    enum ZclStatusCodeT (*optional)(struct ZbZclClusterT *cluster,
        struct ZbZclHeaderT *zclHdrPtr, struct ZbApsdeDataIndT *dataIndPtr);
    /**< Optional commands not parsed into a struct or specific callback. If this is NULL,
     * the cluster will return a Default Response with status of ZCL_STATUS_UNSUPP_CLUSTER_COMMAND.
     * ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error.
     */
};

/**
 * Create a new instance of the Metering Client cluster
 * @param zb Zigbee stack instance
 * @param endpoint Endpoint on which to create cluster
 * @param callbacks Structure containing any callback function pointers for this cluster
 * @param arg Pointer to application data that will later be provided back to the callback functions when invoked
 * @return Cluster pointer, or NULL if there is an error
 */
struct ZbZclClusterT * ZbZclMeterClientAlloc(struct ZigBeeT *zb, uint8_t endpoint,
    struct ZbZclMeterClientCallbacksT *callbacks, void *arg);

/**
 * Send a Get Profile command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for response, including sequence number and tx options
 * @param cmd_req Get Profile command structure
 * @param callback Callback function that will be invoked later when the response is received
 * @param arg Pointer to application data that will later be provided back to the callback function when invoked
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
uint8_t ZbZclMeterClientCommandGetProfileReq(struct ZbZclClusterT *cluster,
    const struct ZbApsAddrT *dst, struct ZbZclMeterClientGetProfileReqT *cmd_req,
    void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/**
 * Send a Get Sampled Data command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for response, including sequence number and tx options
 * @param cmd_req Get Sampled Data command structure
 * @param callback Callback function that will be invoked later when the response is received
 * @param arg Pointer to application data that will later be provided back to the callback function when invoked
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
uint8_t ZbZclMeterClientCommandGetSampledDataReq(struct ZbZclClusterT *cluster,
    const struct ZbApsAddrT *dst, struct ZbZclMeterClientGetSampledDataReqT *cmd_req,
    void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/**
 * Send a Local Change Supply command
 * @param cluster Cluster instance from which to send this command
 * @param dst Destination address for response, including sequence number and tx options
 * @param cmd_req Get Profile command structure
 * @param callback Callback function that will be invoked later when the response is received
 * @param arg Pointer to application data that will later be provided back to the callback function when invoked
 * @return ZCL_STATUS_SUCCESS if successful, or other ZclStatusCodeT value on error
 */
uint8_t ZbZclMeterClientCommandLocalChangeSupplyReq(struct ZbZclClusterT *cluster,
    const struct ZbApsAddrT *dst, struct ZbZclMeterClientLocalChangeSupplyReqT *cmd_req,
    void (*callback)(struct ZbZclCommandRspT *rsp, void *arg), void *arg);

/*lint -restore */

#endif
