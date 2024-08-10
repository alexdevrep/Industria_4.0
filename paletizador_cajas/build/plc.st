TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM Paletizador
  VAR
    Inicio : BOOL;
    Paro : BOOL;
    Motor_cinta_Horizontal : BOOL;
    Motor_cinta_Inclinado : BOOL;
    Motor_cinta_Paletizador : BOOL;
    Contador_Cajas : BOOL;
    Piston_1 : BOOL;
    Sensor_Piston_1 : BOOL;
  END_VAR
  VAR
    CTU0 : CTU;
  END_VAR
  VAR
    Piston_Compuerta : BOOL;
    Sensor_Piston_Compuerta : BOOL;
    Compuerta : BOOL;
    Sensor_Compuerta : BOOL;
  END_VAR
  VAR
    CTU1 : CTU;
  END_VAR
  VAR
    Generador_Cajas : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    Retardo : TIME := T#1000ms;
  END_VAR
  VAR
    Cinta_Pale0 : BOOL;
    Cinta_Pale1 : BOOL;
    Generador_pales : BOOL;
    Cinta_Paletizador : BOOL;
    Sensor_Pale_0 : BOOL;
    Sensor_Pale_1 : BOOL;
    limite_altura : BOOL;
    subir_pale : BOOL;
    bajar_pale : BOOL;
  END_VAR
  VAR
    TOF0 : TOF;
    TOF1 : TOF;
    TON1 : TON;
  END_VAR
  VAR
    Sensor_Pales : BOOL;
    sensor_ascensor : BOOL;
  END_VAR
  VAR
    CTU2 : CTU;
    TON2 : TON;
  END_VAR
  VAR
    sensor_bajada : BOOL;
  END_VAR
  VAR
    TON3 : TON;
    TOF2 : TOF;
    TON4 : TON;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    R_TRIG5 : R_TRIG;
    R_TRIG6 : R_TRIG;
    R_TRIG7 : R_TRIG;
    R_TRIG8 : R_TRIG;
    R_TRIG9 : R_TRIG;
    R_TRIG10 : R_TRIG;
  END_VAR

  Motor_cinta_Horizontal := NOT(Paro) AND (Generador_Cajas OR Inicio OR Motor_cinta_Horizontal OR Motor_cinta_Inclinado OR Motor_cinta_Paletizador);
  Motor_cinta_Inclinado := NOT(Paro) AND (Generador_Cajas OR Inicio OR Motor_cinta_Horizontal OR Motor_cinta_Inclinado OR Motor_cinta_Paletizador);
  Motor_cinta_Paletizador := NOT(Paro) AND (Generador_Cajas OR Inicio OR Motor_cinta_Horizontal OR Motor_cinta_Inclinado OR Motor_cinta_Paletizador);
  R_TRIG1(CLK := Contador_Cajas);
  R_TRIG2(CLK := Sensor_Piston_1);
  CTU0(CU := R_TRIG1.Q, R := R_TRIG2.Q, PV := 2);
  Piston_1 := CTU0.Q;
  R_TRIG3(CLK := Contador_Cajas);
  CTU1(CU := R_TRIG3.Q, R := Sensor_Piston_Compuerta, PV := 6);
  TON0(IN := CTU1.Q, PT := Retardo);
  Piston_Compuerta := TON0.Q;
  Sensor_Piston_Compuerta := Sensor_Piston_Compuerta;
  Generador_Cajas := NOT(Paro) AND (Generador_Cajas OR Inicio OR Motor_cinta_Horizontal OR Motor_cinta_Inclinado OR Motor_cinta_Paletizador);
  Sensor_Piston_1 := NOT(NOT(Sensor_Piston_1));
  TOF1(IN := Sensor_Piston_Compuerta, PT := T#3500ms);
  Compuerta := TOF1.Q;
  TON1(IN := Sensor_Pales, PT := T#2000ms);
  TOF0(IN := TON1.Q, PT := T#3500ms);
  subir_pale := TOF0.Q;
  limite_altura := TOF0.Q;
  bajar_pale := Compuerta;
  R_TRIG4(CLK := sensor_ascensor);
  TON3(IN := sensor_bajada, PT := T#2000ms);
  CTU2(CU := R_TRIG4.Q, R := TON3.Q, PV := 3);
  TON2(IN := CTU2.Q, PT := T#2000ms);
  IF TON2.Q THEN
    limite_altura := TRUE; (*set*)
  END_IF;
  IF TON2.Q THEN
    bajar_pale := TRUE; (*set*)
  END_IF;
  R_TRIG5(CLK := sensor_bajada);
  Cinta_Pale0 := NOT(Paro) AND (Cinta_Pale0 OR Cinta_Pale1 OR Cinta_Paletizador OR Generador_pales OR Inicio OR sensor_ascensor AND R_TRIG5.Q);
  R_TRIG6(CLK := sensor_bajada);
  Cinta_Pale1 := NOT(Paro) AND (Cinta_Pale0 OR Cinta_Pale1 OR Cinta_Paletizador OR Generador_pales OR Inicio OR sensor_ascensor AND R_TRIG6.Q);
  R_TRIG7(CLK := sensor_bajada);
  Cinta_Paletizador := NOT(Paro) AND (Cinta_Pale0 OR Cinta_Pale1 OR Cinta_Paletizador OR Generador_pales OR Inicio OR sensor_ascensor AND R_TRIG7.Q);
  R_TRIG8(CLK := sensor_bajada);
  Generador_pales := NOT(Paro) AND (Cinta_Pale0 OR Cinta_Pale1 OR Cinta_Paletizador OR Generador_pales OR Inicio OR sensor_ascensor AND R_TRIG8.Q);
  TOF2(IN := Sensor_Pales, PT := T#3700ms);
  TON4(IN := TOF2.Q, PT := T#3700ms);
  IF TON4.Q THEN
    Cinta_Pale0 := FALSE; (*reset*)
  END_IF;
  IF TON4.Q THEN
    Cinta_Pale1 := FALSE; (*reset*)
  END_IF;
  IF TON4.Q THEN
    Cinta_Paletizador := FALSE; (*reset*)
  END_IF;
  IF TON4.Q THEN
    Generador_pales := FALSE; (*reset*)
  END_IF;
  R_TRIG9(CLK := sensor_bajada);
  IF NOT(Paro) AND (Cinta_Pale0 OR Cinta_Pale1 OR Cinta_Paletizador OR Generador_pales OR Inicio OR sensor_ascensor AND R_TRIG9.Q) THEN
    limite_altura := FALSE; (*reset*)
  END_IF;
  R_TRIG10(CLK := sensor_bajada);
  IF NOT(Paro) AND (Cinta_Pale0 OR Cinta_Pale1 OR Cinta_Paletizador OR Generador_pales OR Inicio OR sensor_ascensor AND R_TRIG10.Q) THEN
    bajar_pale := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Paletizador;
  END_RESOURCE
END_CONFIGURATION
