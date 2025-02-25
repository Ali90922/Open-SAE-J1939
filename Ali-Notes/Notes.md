# Summary: Where to Focus

Below is a breakdown of the key components in the J1939 stack, their purpose, and what you need to do with them:

| **Component**                              | **Purpose**                                      | **What You Do With It?**                                                                 |
|--------------------------------------------|-------------------------------------------------|-----------------------------------------------------------------------------------------|
| **`Open_SAE_J1939.h`**                     | Main J1939 header file                          | Include this file in your project to access J1939 functionality.                        |
| **`Listen_For_Messages.c`**                | Listens for incoming J1939 messages             | Modify this file to handle custom PGNs (Parameter Group Numbers).                       |
| **`SAE_J1939-21_Transport_Layer/`**        | Handles multi-frame messages                    | Update this layer if you're sending messages longer than 8 bytes.                       |
| **`SAE_J1939-71_Application_Layer/`**      | Handles standard J1939 messages                 | Add logic here to handle new PGNs or SPNs (Suspect Parameter Numbers).                  |
| **`SAE_J1939-73_Diagnostics_Layer/`**      | Handles error codes and diagnostics             | Use this layer to debug DM1/DM2 (Diagnostic Message 1/2) faults.                        |
| **`SAE_J1939-81_Network_Management_Layer/`**| Manages ECU (Electronic Control Unit) addressing| Modify this layer if you're adding new ECUs to the network.                             |
| **`SAE_J1939_Enum.h`**                     | Contains enums for PGNs and SPNs                | Use this file to look up PGN values for message identification.                         |
| **`SAE_J1939_Structs.h`**                  | Defines the J1939 struct                        | This file stores all J1939-related data structures.                                      |

---

### Key Actions:
1. **Include `Open_SAE_J1939.h`** in your project to enable J1939 functionality.
2. **Modify `Listen_For_Messages.c`** to process custom PGNs.
3. **Update the Transport Layer** if working with multi-frame messages (>8 bytes).
4. **Extend the Application Layer** to support new PGNs or SPNs.
5. **Debug using the Diagnostics Layer** for DM1/DM2 fault codes.
6. **Adjust the Network Management Layer** when adding new ECUs.
7. **Refer to `SAE_J1939_Enum.h`** for PGN and SPN values.
8. **Use `SAE_J1939_Structs.h`** to manage J1939 data structures.

---

