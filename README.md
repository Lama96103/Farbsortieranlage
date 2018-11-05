# Farbsortieranlage

## Funktionen, die ihr schreiben müsst damit wir sie aufrufen können

#### int xxx_Init();
Hier könnt ihr am Anfang die Anlage in einen Grundstatus bringen. 
z.B. Lichter auschalten usw.
Return die 0 wenn alles funktioniert hat und 
was anderes wenn es einen Fehler gab.

#### void xxx_ReceiveData(CanRxMsg* msg);
Diese Funktion wird augerufen sobald Daten von eurer Klemme gesendet wurden

#### void xxx_Tick(unsigned int tick);

## Funktionen, die ihr von uns verwenden könnt

#### int Send_Data(uint16_t canId, uint8_t dataLow, uint8_t dataHigh);
Wenn ihr selbst Daten senden wollt. Ihr bekommt die ID der Mailbox wenn dies Erfolgreich war und
*CAN_TxStatus_NoMailBox* wenn es einen Fehler gab.
