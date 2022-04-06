/*
 * DO NOT include this file anywhere besides runtime_config.c - its format is meant to be internal to the configuration
 * parsing.
 */
#ifndef REDPILLLKM_PLATFORMS_H
#define REDPILLLKM_PLATFORMS_H

#include "../shim/pci_shim.h"
#include "platform_types.h"
const struct hw_config supported_platforms[] = {
	 {
        .name = "FS6400",
        .pci_stubs = {
                { .type = __VPD_TERMINATOR__ }
        },
        .emulate_rtc = false,
        .swap_serial = false,
        .reinit_ttyS0 = true,
        .fix_disk_led_ctrl = false,
        .has_cpu_temp = true,
        .hwmon = {
            .sys_thermal = { HWMON_SYS_TZONE_REMOTE1_ID, HWMON_SYS_TZONE_LOCAL_ID, HWMON_SYS_TZONE_REMOTE2_ID },
            .sys_voltage = { HWMON_SYS_VSENS_VCC_ID, HWMON_SYS_VSENS_VPP_ID, HWMON_SYS_VSENS_V33_ID,
                            HWMON_SYS_VSENS_V5_ID, HWMON_SYS_VSENS_V12_ID },
            .sys_fan_speed_rpm = {HWMON_SYS_FAN1_ID, HWMON_SYS_FAN2_ID },
            .hdd_backplane = { HWMON_SYS_HDD_BP_NULL_ID },
            .psu_status = { HWMON_PSU_NULL_ID },
            .sys_current = { HWMON_SYS_CURR_NULL_ID },
        }
    },
	
	{
        .name = "RS4021xs+",
        .pci_stubs = {
                { .type = __VPD_TERMINATOR__ }
        },
        .emulate_rtc = false,
        .swap_serial = false,
        .reinit_ttyS0 = true,
        .fix_disk_led_ctrl = false,
        .has_cpu_temp = true,
        .hwmon = {
            .sys_thermal = { HWMON_SYS_TZONE_REMOTE1_ID, HWMON_SYS_TZONE_LOCAL_ID, HWMON_SYS_TZONE_REMOTE2_ID },
            .sys_voltage = { HWMON_SYS_VSENS_VCC_ID, HWMON_SYS_VSENS_VPP_ID, HWMON_SYS_VSENS_V33_ID,
                            HWMON_SYS_VSENS_V5_ID, HWMON_SYS_VSENS_V12_ID },
            .sys_fan_speed_rpm = {HWMON_SYS_FAN1_ID, HWMON_SYS_FAN2_ID },
            .hdd_backplane = { HWMON_SYS_HDD_BP_NULL_ID },
            .psu_status = { HWMON_PSU_NULL_ID },
            .sys_current = { HWMON_SYS_CURR_NULL_ID },
        }
    },
	{
        .name = "DVA3221",
        .pci_stubs = {
                { .type = __VPD_TERMINATOR__ }
        },
        .emulate_rtc = false,
        .swap_serial = false,
        .reinit_ttyS0 = true,
        .fix_disk_led_ctrl = true,
        .has_cpu_temp = true,
        .hwmon = {
            .sys_thermal = { HWMON_SYS_TZONE_REMOTE1_ID, HWMON_SYS_TZONE_LOCAL_ID, HWMON_SYS_TZONE_REMOTE2_ID },
            .sys_voltage = { HWMON_SYS_VSENS_VCC_ID, HWMON_SYS_VSENS_VPP_ID, HWMON_SYS_VSENS_V33_ID,
                            HWMON_SYS_VSENS_V5_ID, HWMON_SYS_VSENS_V12_ID },
            .sys_fan_speed_rpm = {HWMON_SYS_FAN1_ID, HWMON_SYS_FAN2_ID },
            .hdd_backplane = { HWMON_SYS_HDD_BP_NULL_ID },
            .psu_status = { HWMON_PSU_NULL_ID },
            .sys_current = { HWMON_SYS_CURR_NULL_ID },
        }
    },
};

#endif //REDPILLLKM_PLATFORMS_H
