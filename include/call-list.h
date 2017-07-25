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

#include <glib.h>

struct ofono_voicecall;
struct ofono_phone_number;

/*
 * Can be called by the driver in the dialing callback,
 * when the new call id already known
 */
void ofono_call_list_dial_callback(struct ofono_voicecall *vc,
				   GSList **call_list,
				   const struct ofono_phone_number *ph,
				   int call_id);

/*
 * Called with a list of known calls e.g. clcc.
 * Call list will take ownership of all ofono call within the calls.
 */
void ofono_call_list_notify(struct ofono_voicecall *vc,
			    GSList **call_list,
			    GSList *calls);
