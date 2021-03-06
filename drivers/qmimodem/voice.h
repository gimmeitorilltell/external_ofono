/*
 *
 *  oFono - Open Source Telephony
 *
 *  Copyright (C) 2017 Alexander Couzens <lynxis@fe80.eu>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

enum call_direction;

enum ussd_dcs {
	USS_DCS_ASCII = 0x1,
	USS_DCS_8BIT,
	USS_DCS_UCS2,
};

enum ussd_user_required {
	NO_USER_ACTION_REQUIRED = 0x1,
	USER_ACTION_REQUIRED = 0x2,
};

struct qmi_ussd_data {
	uint8_t dcs;
	uint8_t length;
	uint8_t data[0];
} __attribute__((__packed__));

enum voice_commands {
	QMI_VOICE_CANCEL_USSD = 0x3c,
	QMI_VOICE_USSD_RELEASE_IND = 0x3d,
	QMI_VOICE_USSD_IND = 0x3e,
	QMI_VOICE_SUPS_IND = 0x42,
	QMI_VOICE_ASYNC_ORIG_USSD = 0x43,
};

enum qmi_voice_call_state {
	QMI_CALL_STATE_IDLE = 0x0,
	QMI_CALL_STATE_ORIG,
	QMI_CALL_STATE_INCOMING,
	QMI_CALL_STATE_CONV,
	QMI_CALL_STATE_CC_IN_PROG,
	QMI_CALL_STATE_ALERTING,
	QMI_CALL_STATE_HOLD,
	QMI_CALL_STATE_WAITING,
	QMI_CALL_STATE_DISCONNECTING,
	QMI_CALL_STATE_END,
	QMI_CALL_STATE_SETUP
};

enum qmi_voice_call_type {
	QMI_CALL_TYPE_VOICE = 0x0,
	QMI_CALL_TYPE_VOICE_FORCE,
};

const char *qmi_voice_call_state_name(enum qmi_voice_call_state value);
uint8_t ofono_to_qmi_direction(enum call_direction ofono_direction);
enum call_direction qmi_to_ofono_direction(uint8_t qmi_direction);
int qmi_to_ofono_status(uint8_t status, int *ret);

#define QMI_VOICE_IND_ALL_STATUS 0x2e

#define QMI_VOICE_PARAM_USS_DATA 0x01

#define QMI_VOICE_PARAM_ASYNC_USSD_ERROR 0x10
#define QMI_VOICE_PARAM_ASYNC_USSD_FAILURE_CASE 0x11
#define QMI_VOICE_PARAM_ASYNC_USSD_DATA 0x12

#define QMI_VOICE_PARAM_USSD_IND_USER_ACTION 0x01
#define QMI_VOICE_PARAM_USSD_IND_DATA 0x10
#define QMI_VOICE_PARAM_USSD_IND_UCS2 0x11

/* according to GSM TS 23.038 */
#define USSD_DCS_8BIT 0xf4
#define USSD_DCS_UCS2 0x48
#define USSD_DCS_UNSPECIFIC 0x0f
