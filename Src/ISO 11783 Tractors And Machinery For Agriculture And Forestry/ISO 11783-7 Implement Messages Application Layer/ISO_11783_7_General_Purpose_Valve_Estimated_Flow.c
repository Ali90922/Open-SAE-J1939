/*
 * ISO_11783_7_General_Purpose_Valve_Estimated_Flow.c
 *
 *  Created on: 16 juli 2021
 *      Author: Daniel M�rtensson
 */

#include "ISO_11783_7_Implement_Messages_Application_Layer.h"

/*
 * Send a general purpose valve estimated flow to an ECU
 * PGN: 0x00C600 (50688)
 */
ENUM_J1939_STATUS_CODES ISO_11783_Send_General_Purpose_Valve_Estimated_Flow(J1939 *j1939, uint8_t DA, uint8_t extended_estimated_flow_standard, uint8_t retract_estimated_flow_standard, uint8_t fail_safe_mode, uint8_t valve_state, uint8_t limit, uint16_t extend_estimated_flow_estended, uint16_t retract_estimated_flow_extended) {
	uint32_t ID = (0x0CC6 << 16) | (DA << 8) | j1939->this_ECU_address;
	uint8_t data[8];
	data[0] = extended_estimated_flow_standard;
	data[1] = retract_estimated_flow_standard;
	data[2] = (fail_safe_mode << 6) | (0b11 << 4) | valve_state; 	/* Bit 5 and 6 are reserved */
	data[3] = limit << 5;
	data[4] = data[5] = data[6] = data[7] = 0xFF;					/* All reserved */
	return CAN_Send_Message(ID, data, 0);
}

/*
 * Read a general purpose valve estimated flow from an ECU
 * PGN: 0x00C600 (50688)
 */
void ISO_11783_Read_General_Purpose_Valve_Estimated_Flow(J1939 *j1939, uint8_t SA, uint8_t data[]) {
	j1939->general_purpose_valve_estimated_flow[SA].extend_estimated_flow_standard = data[0];
	j1939->general_purpose_valve_estimated_flow[SA].retract_estimated_flow_standard = data[1];
	j1939->general_purpose_valve_estimated_flow[SA].fail_safe_mode = data[2] >> 6;
	j1939->general_purpose_valve_estimated_flow[SA].valve_state = data[2] & 0b00001111;
	j1939->general_purpose_valve_estimated_flow[SA].limit = data[3] >> 5;
	j1939->general_purpose_valve_estimated_flow[SA].extend_estimated_flow_extended = (data[5] << 8) | data[4];
	j1939->general_purpose_valve_estimated_flow[SA].retract_estimated_flow_extended = (data[7] << 8) | data[6];
}
