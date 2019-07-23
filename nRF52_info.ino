

  
void setup() {
  Serial.begin(115200);
  delay(100);
  
  Serial.print("Chip\t\t: ");

  char variant[4];
  
  switch (NRF_FICR->INFO.PART) {
    case 0x52840: 

      Serial.print("nRF"); 
      Serial.println(NRF_FICR->INFO.PART, HEX); 
            
      variant[0] = NRF_FICR->INFO.VARIANT>>24;
      variant[1] = (NRF_FICR->INFO.VARIANT<<8)>>24;
      variant[2] = (NRF_FICR->INFO.VARIANT<<16)>>24;
      variant[3] = (NRF_FICR->INFO.VARIANT<<24)>>24;
      Serial.print("Variant\t\t: ");
      Serial.println(variant);

      Serial.print("Package\t\t: ");
      switch (NRF_FICR->INFO.PACKAGE) {
        case 0x2004: Serial.println("QIxx - 73-pin aQFN"); break;
        case 0x2005: Serial.println("CKxx - WLCSP"); break;
    }

    break;

    case 0x52832: 
      Serial.print("nRF"); 
      Serial.println(NRF_FICR->INFO.PART, HEX); 
      
  
      variant[0] = NRF_FICR->INFO.VARIANT>>24;
      variant[1] = (NRF_FICR->INFO.VARIANT<<8)>>24;
      variant[2] = (NRF_FICR->INFO.VARIANT<<16)>>24;
      variant[3] = (NRF_FICR->INFO.VARIANT<<24)>>24;
      Serial.print("Variant\t\t: ");
      Serial.println(variant);

      Serial.print("Package\t\t: ");
      Serial.println(NRF_FICR->INFO.PACKAGE, HEX);
      switch (NRF_FICR->INFO.PACKAGE) {
        case 0x2000: Serial.println("QFxx - 48-pin QFN"); break;
        case 0x2001: Serial.println("CHxx - 7x8 WLCSP 56 balls"); break;
        case 0x2002: Serial.println("CIxx - 7x8 WLCSP 56 balls"); break;
        case 0x2005: Serial.println("CKxx - 7x8 WLCSP 56 balls with backside coating"); break;
      }
        break;

    default: Serial.println(" UNKNOWN!!!");
  }

   Serial.print("RAM size\t: ");
   Serial.print(NRF_FICR->INFO.RAM, DEC);
   Serial.println(" kByte");

   Serial.print("Flash size\t: ");
   Serial.print(NRF_FICR->INFO.FLASH, DEC);
   Serial.println(" kByte"); 

   Serial.print("Uniq 64bit device ID\t: ");
   Serial.print((*(__IO uint32_t*)0x10000060), HEX);
   Serial.println((*(__IO uint32_t*)0x10000064), HEX);
}

void loop() {


}
