void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PALETIZADOR_init__(PALETIZADOR *data__, BOOL retain) {
  __INIT_VAR(data__->INICIO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PARO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTOR_CINTA_HORIZONTAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTOR_CINTA_INCLINADO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTOR_CINTA_PALETIZADOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONTADOR_CAJAS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PISTON_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_PISTON_1,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->PISTON_COMPUERTA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_PISTON_COMPUERTA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COMPUERTA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_COMPUERTA,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU1,retain);
  __INIT_VAR(data__->GENERADOR_CAJAS,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->RETARDO,__time_to_timespec(1, 1000, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->CINTA_PALE0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CINTA_PALE1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GENERADOR_PALES,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CINTA_PALETIZADOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_PALE_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_PALE_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LIMITE_ALTURA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUBIR_PALE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BAJAR_PALE,__BOOL_LITERAL(FALSE),retain)
  TOF_init__(&data__->TOF0,retain);
  TOF_init__(&data__->TOF1,retain);
  TON_init__(&data__->TON1,retain);
  __INIT_VAR(data__->SENSOR_PALES,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_ASCENSOR,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU2,retain);
  TON_init__(&data__->TON2,retain);
  __INIT_VAR(data__->SENSOR_BAJADA,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON3,retain);
  TOF_init__(&data__->TOF2,retain);
  TON_init__(&data__->TON4,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  R_TRIG_init__(&data__->R_TRIG6,retain);
  R_TRIG_init__(&data__->R_TRIG7,retain);
  R_TRIG_init__(&data__->R_TRIG8,retain);
  R_TRIG_init__(&data__->R_TRIG9,retain);
  R_TRIG_init__(&data__->R_TRIG10,retain);
}

// Code part
void PALETIZADOR_body__(PALETIZADOR *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,MOTOR_CINTA_HORIZONTAL,,(!(__GET_VAR(data__->PARO,)) && ((((__GET_VAR(data__->GENERADOR_CAJAS,) || __GET_VAR(data__->INICIO,)) || __GET_VAR(data__->MOTOR_CINTA_HORIZONTAL,)) || __GET_VAR(data__->MOTOR_CINTA_INCLINADO,)) || __GET_VAR(data__->MOTOR_CINTA_PALETIZADOR,))));
  __SET_VAR(data__->,MOTOR_CINTA_INCLINADO,,(!(__GET_VAR(data__->PARO,)) && ((((__GET_VAR(data__->GENERADOR_CAJAS,) || __GET_VAR(data__->INICIO,)) || __GET_VAR(data__->MOTOR_CINTA_HORIZONTAL,)) || __GET_VAR(data__->MOTOR_CINTA_INCLINADO,)) || __GET_VAR(data__->MOTOR_CINTA_PALETIZADOR,))));
  __SET_VAR(data__->,MOTOR_CINTA_PALETIZADOR,,(!(__GET_VAR(data__->PARO,)) && ((((__GET_VAR(data__->GENERADOR_CAJAS,) || __GET_VAR(data__->INICIO,)) || __GET_VAR(data__->MOTOR_CINTA_HORIZONTAL,)) || __GET_VAR(data__->MOTOR_CINTA_INCLINADO,)) || __GET_VAR(data__->MOTOR_CINTA_PALETIZADOR,))));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->CONTADOR_CAJAS,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->SENSOR_PISTON_1,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU0.,PV,,2);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,PISTON_1,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->CONTADOR_CAJAS,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->SENSOR_PISTON_COMPUERTA,));
  __SET_VAR(data__->CTU1.,PV,,6);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->CTU1.Q,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->RETARDO,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,PISTON_COMPUERTA,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->,SENSOR_PISTON_COMPUERTA,,__GET_VAR(data__->SENSOR_PISTON_COMPUERTA,));
  __SET_VAR(data__->,GENERADOR_CAJAS,,(!(__GET_VAR(data__->PARO,)) && ((((__GET_VAR(data__->GENERADOR_CAJAS,) || __GET_VAR(data__->INICIO,)) || __GET_VAR(data__->MOTOR_CINTA_HORIZONTAL,)) || __GET_VAR(data__->MOTOR_CINTA_INCLINADO,)) || __GET_VAR(data__->MOTOR_CINTA_PALETIZADOR,))));
  __SET_VAR(data__->,SENSOR_PISTON_1,,!(!(__GET_VAR(data__->SENSOR_PISTON_1,))));
  __SET_VAR(data__->TOF1.,IN,,__GET_VAR(data__->SENSOR_PISTON_COMPUERTA,));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 3500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_VAR(data__->,COMPUERTA,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->SENSOR_PALES,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 3500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,SUBIR_PALE,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,LIMITE_ALTURA,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,BAJAR_PALE,,__GET_VAR(data__->COMPUERTA,));
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->SENSOR_ASCENSOR,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->TON3.,IN,,__GET_VAR(data__->SENSOR_BAJADA,));
  __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TON_body__(&data__->TON3);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTU2.,R,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->CTU2.,PV,,3);
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->CTU2.Q,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TON_body__(&data__->TON2);
  if (__GET_VAR(data__->TON2.Q,)) {
    __SET_VAR(data__->,LIMITE_ALTURA,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TON2.Q,)) {
    __SET_VAR(data__->,BAJAR_PALE,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_VAR(data__->SENSOR_BAJADA,));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->,CINTA_PALE0,,(!(__GET_VAR(data__->PARO,)) && (((((__GET_VAR(data__->CINTA_PALE0,) || __GET_VAR(data__->CINTA_PALE1,)) || __GET_VAR(data__->CINTA_PALETIZADOR,)) || __GET_VAR(data__->GENERADOR_PALES,)) || __GET_VAR(data__->INICIO,)) || (__GET_VAR(data__->SENSOR_ASCENSOR,) && __GET_VAR(data__->R_TRIG5.Q,)))));
  __SET_VAR(data__->R_TRIG6.,CLK,,__GET_VAR(data__->SENSOR_BAJADA,));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->,CINTA_PALE1,,(!(__GET_VAR(data__->PARO,)) && (((((__GET_VAR(data__->CINTA_PALE0,) || __GET_VAR(data__->CINTA_PALE1,)) || __GET_VAR(data__->CINTA_PALETIZADOR,)) || __GET_VAR(data__->GENERADOR_PALES,)) || __GET_VAR(data__->INICIO,)) || (__GET_VAR(data__->SENSOR_ASCENSOR,) && __GET_VAR(data__->R_TRIG6.Q,)))));
  __SET_VAR(data__->R_TRIG7.,CLK,,__GET_VAR(data__->SENSOR_BAJADA,));
  R_TRIG_body__(&data__->R_TRIG7);
  __SET_VAR(data__->,CINTA_PALETIZADOR,,(!(__GET_VAR(data__->PARO,)) && (((((__GET_VAR(data__->CINTA_PALE0,) || __GET_VAR(data__->CINTA_PALE1,)) || __GET_VAR(data__->CINTA_PALETIZADOR,)) || __GET_VAR(data__->GENERADOR_PALES,)) || __GET_VAR(data__->INICIO,)) || (__GET_VAR(data__->SENSOR_ASCENSOR,) && __GET_VAR(data__->R_TRIG7.Q,)))));
  __SET_VAR(data__->R_TRIG8.,CLK,,__GET_VAR(data__->SENSOR_BAJADA,));
  R_TRIG_body__(&data__->R_TRIG8);
  __SET_VAR(data__->,GENERADOR_PALES,,(!(__GET_VAR(data__->PARO,)) && (((((__GET_VAR(data__->CINTA_PALE0,) || __GET_VAR(data__->CINTA_PALE1,)) || __GET_VAR(data__->CINTA_PALETIZADOR,)) || __GET_VAR(data__->GENERADOR_PALES,)) || __GET_VAR(data__->INICIO,)) || (__GET_VAR(data__->SENSOR_ASCENSOR,) && __GET_VAR(data__->R_TRIG8.Q,)))));
  __SET_VAR(data__->TOF2.,IN,,__GET_VAR(data__->SENSOR_PALES,));
  __SET_VAR(data__->TOF2.,PT,,__time_to_timespec(1, 3700, 0, 0, 0, 0));
  TOF_body__(&data__->TOF2);
  __SET_VAR(data__->TON4.,IN,,__GET_VAR(data__->TOF2.Q,));
  __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 3700, 0, 0, 0, 0));
  TON_body__(&data__->TON4);
  if (__GET_VAR(data__->TON4.Q,)) {
    __SET_VAR(data__->,CINTA_PALE0,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON4.Q,)) {
    __SET_VAR(data__->,CINTA_PALE1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON4.Q,)) {
    __SET_VAR(data__->,CINTA_PALETIZADOR,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON4.Q,)) {
    __SET_VAR(data__->,GENERADOR_PALES,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG9.,CLK,,__GET_VAR(data__->SENSOR_BAJADA,));
  R_TRIG_body__(&data__->R_TRIG9);
  if ((!(__GET_VAR(data__->PARO,)) && (((((__GET_VAR(data__->CINTA_PALE0,) || __GET_VAR(data__->CINTA_PALE1,)) || __GET_VAR(data__->CINTA_PALETIZADOR,)) || __GET_VAR(data__->GENERADOR_PALES,)) || __GET_VAR(data__->INICIO,)) || (__GET_VAR(data__->SENSOR_ASCENSOR,) && __GET_VAR(data__->R_TRIG9.Q,))))) {
    __SET_VAR(data__->,LIMITE_ALTURA,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG10.,CLK,,__GET_VAR(data__->SENSOR_BAJADA,));
  R_TRIG_body__(&data__->R_TRIG10);
  if ((!(__GET_VAR(data__->PARO,)) && (((((__GET_VAR(data__->CINTA_PALE0,) || __GET_VAR(data__->CINTA_PALE1,)) || __GET_VAR(data__->CINTA_PALETIZADOR,)) || __GET_VAR(data__->GENERADOR_PALES,)) || __GET_VAR(data__->INICIO,)) || (__GET_VAR(data__->SENSOR_ASCENSOR,) && __GET_VAR(data__->R_TRIG10.Q,))))) {
    __SET_VAR(data__->,BAJAR_PALE,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // PALETIZADOR_body__() 





