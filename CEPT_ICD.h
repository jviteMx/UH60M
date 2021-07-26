#pragma once

namespace CEPT
{
   static const char *SIMULATION_INPUTS = "CEPT_SIMULATION_INPUTS";
   struct SimulationInputs
   {
      bool groundclamp;    //Prevents flight operations boolean
      bool controlloader;  //Control loaders available boolean
      bool freeze;         //Freeze / Pause the simulation. boolean
      bool reset;          //Reset the simulation model boolean
      bool wow;            //Weight on Wheels Switch boolean
      bool gustLock;       //Gust Lock Installed boolean
      bool externalPower;  //External Power is supplied boolean
      double grossweight;  //Aircraft Gross Weight double lbs
      double latitudeic;   //Initial Latitude Position double deg
      double longitudeic;  //Initial Longitude Position double deg
      double altitudeic;   //Initial Altitude Position double ft
      double headingic;    //Initial Heading double deg
      double oat;          //Initial outside air temperature degrees Fahrenheit
      double baropressure; //Initial Barometric pressure at sea level - 29.92 Default
      bool enginesw;       //Initial Engine Condition (0=rotors stopped, 1=rotors turning) boolean
      double engine1_etf;  //ETF of engine 1 - 0.85 - 1.0
      double engine2_etf;  //ETF of engine 2 - 0.85 - 1.0
      double fueltank1;   //Initial fuel in tank 1 - double pounds
      double fueltank2;   //Initial fuel in tank 2 - double pounds
      bool exttanks;    //External tanks present boolean
      bool refillExpendables;  //Refill expendables
      bool stormSim;      // Simulate storm
      bool wowOverride;    //Override button for Weight on Wheels switch
      bool rotorModel;     //Activates rotor model boolean
      double northSlope;   //terrain slope to the north.
      double eastSlope;    //terrain slope to the east.
   };

   static const char *AFS_SENSORS = "AFS_SENSORS";
   struct Sensors
   {
      double radalt;             // Indicated radar altitude (feet)
      bool radalt_valid;         // Indicates that the radar altimeter is operating
      double adc1_baro_altitude; // Barometric altitude from #1 ADC
      bool adc1_valid;           // Indicates #1 ADC is operating
      double adc2_baro_altitude; // Barometric altitude from #2 ADC
      bool adc2_valid;           // Indicates #1 ADC is operating
      bool egi1_valid;           // Indicates #1 EGI is operating
      bool egi2_valid;           // Indicates #2 EGI is operating
   };

   static const char *ELECTRICAL_SYSTEM = "CEPT_ELECTRICAL_SYSTEM";
   struct ElectricalSystem
   {
      bool No1Generator;      //The Number 1 Generator is on line
      bool No2Generator;      //The Number 2 Generator is on line
      bool No1ACPrimary;      //The Number 1 AC Primary bus is energized
      bool No2ACPrimary;      //The Number 2 AC Primary bus is energized
      bool No1Converter;      //The Number 1 AC/DC Converter is operating
      bool No2Converter;      //The Number 2 AC/DC Converter is operating
      bool No1DCPrimary;      //The Number 1 DC Primary bus is energized
      bool No2DCPrimary;      //The Number 2 DC Primary bus is energized
      bool No1DCEssential;    //The Number 1 DC Essential bus is energized
      bool No2DCEssential;    //The Number 2 DC Essential bus is energized
      bool No1Battery;        //The Number 1 Battery bus is energized
      bool No2Battery;        //The Number 2 Battery bus is energized
      bool No1BatteryUtility; //The Number 1 Battery Utility bus is energized
      bool No2BatteryUtility; //The Number 2 Battery Utility bus is energized
   };

   static const char *HYDRAULIC_SYSTEM = "CEPT_HYDRAULIC_SYSTEM";
   struct HydraulicSystem
   {
      bool No1Pump;           // The number 1 hydraulic pump is powered and functioning 
      bool No2Pump;           // The number 2 hydraulic pump is powered and functioning
      bool BackupPump;        // The backup hydraulic pump is powered and functioning
      UINT8 No1PumpRsvr;      // The number 1 pump reservoir level %
      UINT8 No2PumpRsvr;      // The number 2 pump reservoir level %
      UINT8 BackupPumpRsvr;   // The backup pump reservoir level %
      bool PrimaryServos1;    // Primary servos 1 functioning
      bool PrimaryServos2;    // Primary servos 2 functioning
      bool PilotAssistServos; // Pilot assist ( SAS, SAS/Boost ) servos functioning
      bool TailRotorServo1;   // Tail Rotor Servo 1 functioning
      bool TailRotorServo2;   // Tail Rotor Servo 2 functioning
   };

   static const char *CIRCUIT_BREAKERS = "CEPT_CIRCUIT_BREAKERS";
   struct CircuitBreakers
   {
      bool No1Converter;
      bool LeftPitotHeat;
      bool No1EngineOverspeed;
      bool BusTieController1;
      bool CopilotCDU;
      bool IcsSec;
      bool No2Converter;
      bool RightPitotHeat;
      bool No2EngineOverspeed;
      bool BusTieController2;
      bool PilotIcs;
      bool PilotCDU;
      bool IcsIcu;
      bool No1DcuSec;
      bool CduSec;
      bool No2DcuSec;
      bool No1AutoXfmr;
      bool No2AutoXfmr;
   };

   static const char *MALFUNCTIONS = "CEPT_MALFUNCTIONS";
   struct Malfunctions
   {
      // Electrical
      bool APU_OIL_TEMP_HIGH;        //APU Oil temperature high
      bool APU_FIRE;                 //APU Fire
      bool APU_SEQUENCE_FAILURE;     //APU Sequence Failure
      bool APU_ACCUM_LEAK;           //APU Accumulator Leak
      double APU_ACCUM_LEAK_TAU;     //APU Accumulator Rate Time Constant
      bool BATTERY_LOW_CHARGE;       //Battery low charge
      bool GENERATOR_1_FAILURE;      //Generator 1 failure
      bool GENERATOR_2_FAILURE;      //Generator 2 failure
      bool DC_CONVERTER_1_FAILURE;   //DC converter 1 failure
      bool DC_CONVERTER_2_FAILURE;   //DC converter 2 failure
      bool DC_ESNTL_BUS_1_FAILURE;   //DC Essential bus 1 failure
      bool DC_ESNTL_BUS_2_FAILURE;   //DC Essential bus 2 failure
      bool FMS_1_POWER_FAILURE;
      bool FMS_2_POWER_FAILURE;
      bool MFD_1_POWER_FAILURE;
      bool MFD_2_POWER_FAILURE;
      bool MFD_3_POWER_FAILURE;
      bool MFD_4_POWER_FAILURE;
      bool LIGHTNING_STRIKE;         //Lightning Strike

      // Avionics
      bool AVCS_BIT_FAILURE;
      bool FAIL_ICS_LEFT_PILOT;
      bool FAIL_ICS_RIGHT_PILOT;
      bool EGI_1_FAILURE;
      bool EGI_2_FAILURE;
      bool IDM_BIT_FAILURE;
      bool IDM_COMMUNICATIONS_FAILURE;
      bool MFD_1_COMM_FAILURE;
      bool MFD_4_COMM_FAILURE;

      // CHIP
      bool CHIP_L_INPUT_MDL;
      bool CHIP_R_INPUT_MDL;
      bool CHIP_L_ACCESS_MDL;
      bool CHIP_R_ACCESS_MDL;
      bool CHIP_MAIN_MDL_SUMP;
      bool CHIP_TAIL_XMSN;
      bool CHIP_INTERMED_XMSN;
      bool CHIP_ENG_1;
      bool CHIP_ENG_2;

      // Engines
      bool ENG_1_FAILURE;             //Engine 1 general failure
      bool ENG_2_FAILURE;             //Engine 2 general failure
      bool ENG_1_FIRE;                //Engine 1 fire
      bool ENG_2_FIRE;                //Engine 2 fire
      bool ENG_1_PCL_FAIL;            //PCL 1 failure
      bool ENG_2_PCL_FAIL;            //PCL 2 failure
      bool ENG_1_TGT_ZERO;            //TGT 1 zero
      bool ENG_2_TGT_ZERO;            //TGT 2 zero
      bool ENG_1_OIL_PRESS_HIGH;      //Eng 1 oil pressure high
      bool ENG_2_OIL_PRESS_HIGH;      //Eng 2 oil pressure high
      bool ENG_1_OIL_PRESS_LOW;       //Eng 1 oil pressure low
      bool ENG_2_OIL_PRESS_LOW;       //Eng 2 oil pressure low
      bool ENG_1_OIL_PRESS_ZERO;      //Eng 1 pressure zero
      bool ENG_2_OIL_PRESS_ZERO;      //Eng 2 pressure zero
      bool ENG_1_OIL_TEMP_HIGH;       //Eng 1 oil temperature high
      bool ENG_2_OIL_TEMP_HIGH;       //Eng 2 oil temperature high
      bool ENG_1_OIL_TEMP_LOW;        //Eng 1 oil temperature low
      bool ENG_2_OIL_TEMP_LOW;        //Eng 2 oil temperature low
      bool ENG_1_OIL_TEMP_ZERO;       //Eng 1 oil temperature zero
      bool ENG_2_OIL_TEMP_ZERO;       //Eng 2 oil temperature zero
      bool ENG_1_TORQUE_SPLIT_HIGH;   //Eng 1 torque split high
      bool ENG_2_TORQUE_SPLIT_HIGH;   //Eng 2 torque split high
      bool ENG_1_TORQUE_SPLIT_LOW;    //Eng 1 torque split low
      bool ENG_2_TORQUE_SPLIT_LOW;    //Eng 2 torque splot low
      bool ENG_1_TORQUE_SENSOR_FAIL;  //Eng 1 torque sensor failure
      bool ENG_2_TORQUE_SENSOR_FAIL;  //Eng 2 torque sensor failure
      bool ENG_1_ALTERNATOR_FAIL;     //Eng 1 alternator failure
      bool ENG_2_ALTERNATOR_FAIL;     //Eng 2 alternator failure
      bool ENG_1_COMPRESSOR_STALL;    //Eng 1 compressor stall
      bool ENG_2_COMPRESSOR_STALL;    //Eng 2 compressor stall
      bool ENG_1_HIGH_SPEED_SHAFT_FAIL;   //Eng 1 high speed shaft failure
      bool ENG_2_HIGH_SPEED_SHAFT_FAIL;   //Eng 2 high speed shaft failure
      bool ENG_1_POWER_ERRATIC;       //Eng 1 power erratic/variation
      bool ENG_2_POWER_ERRATIC;       //Eng 2 power erratic/variation
      bool ENG_1_TORQUE_ERRATIC;      //Eng 1 torque erratic
      bool ENG_2_TORQUE_ERRATIC;      //Eng 2 torque erratic
      bool ENG_1_TGT_ERRATIC;         //Eng 1 TGT erratic
      bool ENG_2_TGT_ERRATIC;         //Eng 2 TGT erratic
      bool ENG_1_NG_ERRATIC;          //Eng 1 Ng erratic
      bool ENG_2_NG_ERRATIC;          //Eng 2 Ng erratic
      bool ENG_1_OIL_FILTER_BYPASS;   //Eng 1 oil filter bypass
      bool ENG_2_OIL_FILTER_BYPASS;   //Eng 2 oil filter bypass
      bool ENG_1_HOT_START;           //Eng 1 hot start
      bool ENG_2_HOT_START;           //Eng 2 hot state
      bool ENG_1_HUNG_START;          //Eng 1 hung start
      bool ENG_2_HUNG_START;          //Eng 2 hung start
      bool ENG_1_EXCESS_TGT;          //Eng 1 excess TGT
      bool ENG_2_EXCESS_TGT;          //Eng 2 excess TGT
      bool ENG_1_STARTER_FAILURE;     //Eng 1 starter failure
      bool ENG_2_STARTER_FAILURE;     //Eng 2 starter failure
      bool ENG_1_FLAMEOUT;            //Eng 1 flameout
      bool ENG_2_FLAMEOUT;            //Eng 2 flameout

      // Dual Engine Failures
      bool DUAL_INCREASE_RPMR;        //Increasing RPMR
      bool DUAL_DECREASE_RPMR;        //Decreasing RPMR

      // Hydraulics
      bool HYDRAULIC_PUMP_1_FAIL;
      bool HYDRAULIC_PUMP_2_FAIL;
      bool HYDRAULIC_PUMP_1_FAIL_NO_BU;
      bool HYDRAULIC_PUMP_2_FAIL_NO_BU;
      bool HYDRAULIC_PUMP_1_LEAK;
      bool HYDRAULIC_PUMP_1_LEAK_TAIL;
      bool HYDRAULIC_PUMP_2_LEAK;
      bool HYDRAULIC_PUMP_2_LEAK_SAS;

      // Rotor Brake
      bool ROTOR_BRAKE_ACTUATION_FAIL;
      bool ROTOR_BRAKE_ADVISORY_LIGHT_ON;
      bool ROTOR_BRAKE_HANDLE_FAIL;
      bool ROTOR_BRAKE_GUSTLOCK_FAIL;

      // Fuel System
      bool FUEL_FILTER_1_BYPASS;      //Fuel filter 1 bypass
      bool FUEL_FILTER_2_BYPASS;      //Fuel filter 2 bypass
      bool FUEL_PRESSURE_1_LEAK;      //Fuel pressure 1 leak
      bool FUEL_PRESSURE_2_LEAK;      //Fuel pressure 2 leak
      double FUEL_PRESSURE_1_LEAK_TAU;    //fuel pressure 1 leak time constant [sec]
      double FUEL_PRESSURE_2_LEAK_TAU;    //fuel pressure 2 leak time constant [sec]
      bool FUEL_ENGDRIVEN_PUMP_1_FAIL;    //Engine 1 driven fuel pump failure
      bool FUEL_ENGDRIVEN_PUMP_2_FAIL;    //Engine 2 driven fuel pump failure
      bool FUEL_ELECTRIC_PUMP_1_FAIL;     //Electric pump 1 failure
      bool FUEL_ELECTRIC_PUMP_2_FAIL;     //Electric pump 2 failure

      // Transmission
      bool XMSN_MAIN_OIL_TEMP_HIGH;       //Main Transmission Oil Temperature High
      bool XMSN_MAIN_OIL_PRESS_HIGH;      //Main transmission oil pressure high
      bool XMSN_INTERMED_OIL_TEMP_HIGH;   //Intermediate oil temperature high
      bool XMSN_TAIL_OIL_TEMP_HIGH;       //Tail Transmission Oil Temperature High
      bool XMSN_LUBE_PUMP_PRESS;          //Main Transmission Lube Pump Pressure
      bool XMSN_LUBE_PUMP_SCAVENGE;       //Main Transmission Lube Pump Scavenge
      bool XMSN_ABRUPT_MAIN_PRESS_LOSS;   //Abrupt Main Transmission Oil Pressure Loss
      bool XMSN_GRADUAL_MAIN_PRESS_LOSS;  //Gradual Main Transmission Oil Pressure Loss

      // ASE malfunctions
      bool LeftFrontCmws;
      bool LeftAftCmws;
      bool RightFrontCmws;
      bool RightAftCmws;
      bool LeftFrontLwr;
      bool LeftAftLwr;
      bool RightFrontLwr;
      bool RightAftLwr;
      bool LeftFrontRwr;
      bool LeftAftRwr;
      bool RightFrontRwr;
      bool RightAftRwr;
      UINT8 CmwsProcessor;       //CMWS processor (0=ok, 1=degraded, 2=failed) 
      bool FifthCmwsProcessor;
      bool LaserProcessor;
      bool RadarProcessor;
      bool CDBand;
      bool FifthCmws;
      bool Saturated;

      // Circuit breakers - to be removed...
      bool No1Converter;
      bool LeftPitotHeat;
      bool No1EngineOverspeed;
      bool BusTieController1;
      bool CopilotCDU;
      bool IcsSec;
      bool No2Converter;
      bool RightPitotHeat;
      bool No2EngineOverspeed;
      bool BusTieController2;
      bool PilotIcs;
      bool PilotCDU;
      bool IcsIcu;
      bool No1DcuSec;
      bool CduSec;
      bool No2DcuSec;
      bool No1AutoXfmr;
      bool No2AutoXfmr;
   };

   static const char *OVERHEAD_PANEL="CEPT_OVERHEAD_PANEL";
   struct OverheadPanel
   {
      double pcl1;                  //Power/Throttle Lever Co-pilot Side double deg
      double pcl2;                  //Power/Throttle Lever Pilot Side double deg
      bool pclpullout1;             //Power level pull-out position 0=in, 1=out
      bool pclpullout2;             //Power level pull-out position 0=in, 1=out
      INT32 rotorBrake;             //Rotor breake position
      UINT8 fuelsel1;               //Fuel Selector #1 Co-pilot Side (0=off, 1=direct, 2=crossfeed) uint8
      UINT8 fuelsel2;               //Fuel Selector #2 Pilot Side (0=off, 1=direct, 2=crossfeed) uint8
      bool starter1;                //Engine #1 Bleed Air Valve (Switch) boolean
      bool starter2;                //Engine#2 Bleed Air Valve (Switch) boolean
      bool antiicesw1;              //Anti-ice Switch for Engine #1 boolean
      bool antiicesw2;              //Anti-ice Switch for Engine #2 boolean
      bool cabinheat1;              //Anti-ice Switch for Engine #1	boolean
      bool cabinheat2;              //Anti-ice Switch for Engine #2	boolean
      UINT8 EngineSpeedTrim;        //0=OFF, 1=INCR, 2=DECR
      bool Engine1OverspeedTest;    //Boolean
      bool Engine2OverspeedTest;    //Boolean
      UINT8 FireDetectionTest;      //0=OFF, 1=1, 2=2
      bool LampsTest;               //Boolean
      UINT8 SecondaryLights;        //0=OFF, 1=WHITE, 2=BLUE
      double SecondaryLightsValue;  //Dimmer Value
      bool No1FuelBoostPump;        //Boolean
      bool No2FuelBoostPump;        //Boolean
      bool ExternalPower;           //Boolean
      bool APUControl;              //Boolean
      UINT8 FuelPumpState;          //0=OFF, 1=PRIME, 2=APU_BOOST
      UINT8 AirSource;              //0=OFF, 1=Engine, 2=APU
      UINT8 StnbyInstBatt;          //0=OFF, 1=ON, 2=TEST
      UINT8 No1Batt;                //0=OFF, 1=ON, 2=TEST
      UINT8 No2Batt;                //0=OFF, 1=ON, 2=TEST
      UINT8 ApuGen;                 //0=OFF, 1=ON, 2=TEST
      UINT8 No1Gen;                 //0=OFF, 1=ON, 2=TEST
      UINT8 No2Gen;                 //0=OFF, 1=ON, 2=TEST
      bool VibrationControl;        //Boolean
      bool PitotHeatLeft;           //Boolean
      bool PitotHeatRight;          //Boolean
      bool FuelIndicatorTest;       //Boolean
      bool ApuTHandlePulled;        //Boolean
   };

   static const char *OVERHEAD_PANEL_INDICATIONS = "CEPT_OVERHEAD_PANEL_INDICATIONS";
   struct OverheadPanelIndications
   {
      bool APU_Fire;
      bool Engine1_Fire;
      bool Engine2_Fire;
      bool EmergencyReleaseTest;
      bool OilHot;
      bool APU_Fail;
      bool BatteryGood;
      bool BatteryLow;
      bool ACC_Low;
      bool APU_On;
      bool Starter1Engaged;
      bool Starter2Engaged;
      double rotorBrakePressure;
   };

   static const char *INSTRUMENT_PANEL = "CEPT_INSTRUMENT_PANEL";
   struct InstrumentPanel
   {
      bool EngineIgnition;
      bool MasterCaution;
      bool AcknowledgeAll;
      bool Rev1Att;
      bool Rev1Fms;
      bool Rev1Adc;
      bool Rev1Hdg;
      bool Rev1Dcu;
      bool Rev1Vel;
      bool Rev2Att;
      bool Rev2Fms;
      bool Rev2Adc;
      bool Rev2Hdg;
      bool Rev2Dcu;
      bool Rev2Vel;
      bool EsisKnobButton;
      bool EsisMenuButton;
      UINT8 EsisKnob; // 00-FF 16 position knob
   };

   static const char *INSTRUMENT_PANEL_INDICATIONS = "CEPT_INSTRUMENT_PANEL_INDICATIONS";
   struct InstrumentPanelIndications
   {
      bool MasterCaution;
      bool Engine1Out;
      bool Engine2Out;
      bool Fire;
      bool LowRotorRpm;
   };

   enum eIcsTxPosition
   {
      kTxIcs = 0,
      kTx1,
      kTx2,
      kTx3,
      kTx4,
      kTx5,
      kTx6,
      kTx7,
      kTxRmt,
      kTxBU,
      kTxPVT
   };

   struct Ics
   {
      bool Com1Receive;
      double Com1Volume;
      bool Com2Receive;
      double Com2Volume;
      bool Com3Receive;
      double Com3Volume;
      bool Com4Receive;
      double Com4Volume;
      bool Com5Receive;
      double Com5Volume;
      bool Com6Receive;
      double Com6Volume;
      bool Com7Receive;
      double Com7Volume;
      bool Nav1Receive;
      double Nav1Volume;
      bool Nav2Receive;
      double Nav2Volume;
      bool Nav3Receive;
      double Nav3Volume;
      bool Nav4Receive;
      double Nav4Volume;
      bool IcsButton;
      bool VoxButton;
      bool HotMicButton;
      bool CallButton;
      UINT8 TxPosition;
      UINT8 mvol;
   };

   enum eExternalTest
   {
      kNone = 0,
      kSkip,
      kAll,
      kStabilatorOnly
   };

   enum eAfcsTestStatus
   {
      kAfcsTestOff = 0,
      kCriticalFccTestActive,
      kExternalTestsActive,
      kSeverTestActive,
      kIocTestActive,
      kDpramTestActive,
      kAfcsTestDone
   };

   static const char *LOWER_CONSOLE = "CEPT_LOWER_CONSOLE";
   struct LowerConsole
   {
      bool sas1sw; //SAS#1 Switch boolean
      bool sas2sw; //SAS#2 Switch boolean
      bool trimsw; //Trim Switch boolean
      bool fpssw; //Flight Path Stabilization Switch boolean
      bool stabslewup; //Stabilator slew up switch boolean
      bool stabslewdwn; //Stabilator slew down switch boolean
      bool stabauto; //Stabilator auto mode switch boolean
      bool stabtest;//Stabilator test switch boolean
      bool sasboost; //SAS Boost control switch
      bool fccreset1;   //Failure Reset of FCC #1 switch
      bool fccreset2;   //Failure Reset of FCC #2 switch
      bool EmergencyZeroize;
      bool UhfGuard;
      bool IffEmergency;
      UINT8 FmsMode;    //0=AUTO,1=FMS1,2=FMS2
      bool TailServoBackup;
      UINT8 BackupPumpStatus; //0=AUTO, 1=ON, 2=OFF
      UINT8 HydraulicLeakTest; //0=OFF, 1=TEST, 2=RESET
      UINT8 TailServoOff; //0=NORMAL, 1=1st Stage, 2=2nd Stage
      bool Egi1Power;
      UINT8 RadAltPower; //0=OFF, 1=ON, 2=TEST
      bool IffMode4Hold;
      bool Egi2Power;
      UINT8 Arc231Power; //0=NORM, 1=PLAIN, 2=CYPHER
      Ics Ics1;
      Ics Ics2;
      bool IosHotMike;
      bool IosInlineMike;
      bool IosFootSwitch;
      bool ParkingBrake; // Parking brake engaged
      bool StartActTest; // Toggle from FMS sk-2 (0=stop, 1=start/run)
      UINT8 ChooseExtTest; //0=no selection, 1=skip external tests, 2=do all tests, 3=do stab test only
      UINT8 AfcsTestStatus; // AFCS test status: 0=Off; 1=Critical FCC Test; 2=External Tests; 3=Sever Test; 4=IOC Test; 5=DPRAM Test; 6=Done
   };

   struct IcsIndications
   {
      bool IcsLight;
      bool VoxLight;
      bool HotMicLight;
      bool CallLight;
      bool ICULight;
   };

   enum eExternalTestStatus
   {
      kExtTestOff = 0,
      kCollectiveTestActive,
      kYawTestActive,
      kCyclicTestActive,
      kPitchSasTestActive,
      kRollSasTestActive,
      kYawSasTestActive,
      kStabToMidTest1Active,
      kStabA1InA2OutTestActive,
      kStabA1OutA2InTestActive,
      kStabToMidTest2Active,
      kStabSlowUpTestActive,
      kStabDownTestActive,
      kExtTestDone
   };

   static const char *LOWER_CONSOLE_INDICATIONS = "CEPT_LOWER_CONSOLE_INDICATIONS";
   struct LowerConsoleIndications
   {
      bool sas1_eng;       //SAS#1 Engage boolean
      bool sas2_eng;       //SAS#2 Engage boolean
      bool trim_eng;       //Trim Engage boolean
      bool fps_eng;        //Flight Path Stabilization Engage boolean
      bool automode_engAGED;   //Stabilator Auto Mode Engage boolean
      bool sasboost_eng;   //SAS Boost engaged boolean
      bool fcc1fail;       //FCC 1 Failed flag
      bool fcc2fail;       //FCC 2 Failed flag
      bool dts1Light;      //LED for DTS, slot 1
      bool dts2Light;      //LED for DTS, slot 2
      bool parkingBrakeEngaged; //Keep parking brake handle up/engaged
      IcsIndications Ics1;
      IcsIndications Ics2;
      bool stabhorn_fcc1;	//Stabilator manual mode warning horn from FCC 1
      bool stabhorn_fcc2;	//Stabilator manual mode warning horn from FCC 2
      UINT8 ext_test_status;  //External test status: 0=Off; 1=Collective Test; 2=Yaw Test; 3=Cyclic Test; 4=Pitch SAS Test; 5=Roll SAS Test; 6=Yaw SAS Test;
      //       7=Stab to Mid Time 1; 8=Act1 In, Act2 Out; 9=Act1 Out, Act2 Int; 10=Stab to Mid Time 2; 11=Stab Slow Up; 12=Stab Down; 13=Done
      bool ext_test_done;   //all External tests completed
      bool pitch_test_fail; //Pitch trim actuator test failed
      bool roll_test_fail;  //Roll trim actuator test failed
      bool yaw_test_fail;   //Yaw trim actuator test failed
      bool coll_test_fail;  //Collective trim actuator test failed
      bool stab_test_fail;	//Stabilator actuator test failed
   };

   static const char *EICAS_ALERTS = "CEPT_EICAS_ALERTS";
   struct EICASAlerts
   {
      bool afcs_fail;         //Failure of one or both FCCs	
      bool fd_couple_fail;    //FD function disengaged due to failure while coupled
      bool flt_dir_fail;      //FD function disengaged due to failure	
      bool fps_fail;          //FPS function disengaged due to failure	
      bool sas_off;           //SAS1 and SAS2 off due to failure	
      bool stab_manual_mode;  //Stabilator system operating in manual mode	
      bool trim_fail;         //Trim actuators not responding to FCC	
      bool sas_degraded;      //SAS function disengaged due to failure	
      bool eng1_out;          //#1 Engine NG is below 55%	
      bool eng2_out;          //#2 Engine NG is below 55%	
      bool low_rotor_rpm;     //NR is below approximately 96%	
      bool check_eicas;       //Indicates engine parameters are not within normal range
      bool eng1_oil_hot;      //#1 Engine oil temperature is above 150 deg C	
      bool eng1_oil_press;    //#1 Engine oil pressure is too low	
      bool eng1_starter_on;   //#1 Engine start circuit is actuated	
      bool eng2_oil_hot;      //#2 Engine oil temperature is above 150 deg C	
      bool eng2_oil_press;    //#2 Engine oil pressure is too low	
      bool eng2_starter_on;   //#2 Engine start circuit is actuated	
      bool fuel1_low;         //#1 Fuel tank is below minimum level	
      bool fuel2_low;         //#2 Fuel tank is below minimum level
      bool main_xmsn_oil_hot; //Main transmission oil temperature is above 140 deg C
      bool main_xmsn_press;   //Main transmission oil pressure is below about 21 psi
      bool backup_rsvr_low;   //Backup pump reservoir low
      bool pump1_rsvr_low;    //#1 Hydraulic pump reservoir low
      bool pump2_rsvr_low;    //#2 Hydraulic pump reservoir low
      bool fuel_pump_prime_bst;   // fuel pump is in prime or boost
      bool boost_off;         //Boost servos off
   };

   static const char *PILOT_FLIGHT_CONTROLS = "CEPT_PILOT_FLIGHT_CONTROLS";
   static const char *COPILOT_FLIGHT_CONTROLS = "CEPT_PILOT_COFLIGHT_CONTROLS";
   struct FlightControls
   {
      double xastkpos;  //Cyclic Lateral Position double %
      double xbstkpos;  //Cyclic Longitudinal Position double %
      double xcstkpos;  //Collective Position double %
      double xppedpos;  //Pedal Position double %
      double xatrmpos;	//Cyclic Lateral Trim Position %
      double xbtrmpos;	//Cyclic Longitudinal Trim Position %
      double xctrmpos;	//Collective Trim Position %
      double xptrmpos;	//Pedal Trim Position %
      double xaforce;   //Cyclic Lateral force lbs
      double xbforce;   //Cyclic Longitudinal force lbs
      double xcforce;   //Collective Force lbs
      double xpforce;   //Pedal force lbs
      bool cycbplft;    //Cyclic AFCS Beep Switch Left boolean
      bool cycbprt;     //Cyclic AFCS Beep Switch Right boolean
      bool cycbpfwd;    //Cyclic AFCS Beep Switch Forward boolean
      bool cycbpaft;    //Cyclic AFCS Beep Switch Aft boolean
      bool cycbpctr;    //Cyclic AFCS Switch Center Plunge boolean
      bool colbplft;    //Collective AFCS Beep Switch Left boolean
      bool colbprt;     //Collective AFCS Beep Switch Right boolean
      bool colbpup;     //Collective AFCS Beep Switch Up boolean
      bool colbpdn;     //Collective AFCS Beep Switch Down boolean
      bool colsel;      // Collective Select Button
      double colratex;  // Collective Cursor x position
      double colratey;  // Collective Cursor y position
      bool cyctrmrel;   //Cyclic Trim Release Switch boolean
      bool coltrmrel;   //Collective Trim Release Switch boolean
      bool yawtrmrel;   //Pedal (YAW) Trim Release Switch boolean
      bool brake_sw;    //Brake switch on the pedals
      bool rmtstdby;    //Cyclic Remote Standby Switch boolean
      bool goaround;    //Cyclic Go Around Switch boolean
      UINT8 trigger;    //Cyclic trigger position [0=OFF,1=ICS,2=Radio]
      bool footSwitch;  //Radio foot switch
      bool vox_caut;    //Cyclic vox caution button boolean
      UINT8 radio_sw;   //Collective Radio switch [0=OFF,1=UP,2=DOWN, 3=LEFT, 4=RIGHT]
      bool landing_lt;  //Collective landing light switch boolean
      bool search_lt;   //Collective search light switch boolean
      bool cycslewup;   //Cyclic slew up switch
   };

   static const char *TRIM_COMMANDS = "CEPT_TRIM_COMMANDS";
   struct TrimCommands
   {
      double rtrmcmd;   //Roll trim command %
      double ptrmcmd;   //Pitch trim command %
      double ctrmcmd;   //Collective trim command %
      double ytrmcmd;   //Yaw trim command %
      bool rtmeng;		//Roll trim engaged
      bool ptmeng;		//Pitch trim engaged
      bool ctmeng;		//Collective trim engaged
      bool ytmeng;		//Yaw trim engaged
      double rtrmratecmd;	//Roll trim rate command %/sec
      double ptrmratecmd;	//Pitch trim rate command %/sec
      double ctrmratecmd;	//Collective trim rate command %/sec
      double ytrmratecmd;	//Yaw trim rate command %/sec
   };

   static const char *INSTRUMENTS = "CEPT_INSTRUMENTS";
   struct Instruments
   {
      double latitude; //Latitude Position double deg
      double longitude; //Longitude Position double deg
      double altitude; //Absolute Altitude double ft
      double airspeed; //Indicated Airspeed double knots
      double groundspeed; //Ground speed double knots
      double pitch; //Pitch Attitude double deg
      double roll; //Roll Attitude double deg
      double heading; //True Heading double deg
      double track; //True ground track double deg
      double vclimb; //Rate of Climb (NED Frame) double ft/min
      double turnrate; //Rate of Turn double deg/sec
      double trimball; //Trim ball based on lateral acceleration double deg
      double stabangle; //Stabilator Angle double deg
      double oat; //Outside Air Temperature double deg F
      double vx; //Longitudinal X-velocity, local level frame, +forward kts
      double vy; //Lateral Y-velocity, local level frame, +right kts
      double ax; //Longitudinal X-acceleration, local level frame, +forward fps2
      double ay; //Lateral Y-acceleration, local level frame, +right fps2
      double az; //Vertical Z-acceleration, local level frame (no gravity), +down fps2
   };

   static const char *ENGINE_DATA = "CEPT_ENGINE_DATA";
   struct EngineData
   {
      double MainRotorSpeed; //Main Rotor Speed double %
      double GearTemp; //Gearing Module Oil Temperature of Engine #1 double deg C
      double GearPressure; //Gearing Module Oil Pressure of Engine #1 double psi
      double Engine1GasTurbineSpeed; //Gas Turbine Speed of Engine #1 double %
      double Engine1GasTurbineTemp; //Exit Gas Temperature of Engine #1 double deg C
      double Engine1Torque; //Shaft Torque of Engine #1 double %
      double Engine1PowerTurbineSpeed; //Power Turbine Speed of Engine #1 double %
      double Engine1OilTemp; //Oil Temperature of Engine #1 double deg C
      double Engine1OilPressure; //Oil Pressure of Engine #1 double psi
      double Engine1FuelRate; //Fuel Flow for Engine #1 double pounds/sec
      double Engine2GasTurbineSpeed; //Gas Turbine Speed of Engine #2 double %
      double Engine2GasTurbineTemp; //Exit Gas Temperature of Engine #2 double deg C
      double Engine2Torque; //Shaft Torque of Engine #2 double %
      double Engine2PowerTurbineSpeed; //Power Turbine Speed of Engine #2 double %
      double Engine2OilTemp; //Oil Temperature of Engine #2 double deg C
      double Engine2OilPressure; //Oil Pressure of Engine #2 double psi
      double Engine2FuelRate; //Fuel Flow for Engine #2 double pounds/sec
      double MainFuelWeight1; //Fuel Weight for Tank #1 double pounds
      double MainFuelWeight2; //Fuel Weight for Tank #2 double pounds
      double MainFuelWeight1Indication; //Fuel Weight Indicated for Tank #1 double pounds
      double MainFuelWeight2Indication; //Fuel Weight Indicated for Tank #2 double pounds
      double Engine1FuelPressure; //Fuel Pressure of Engine #1 double psi
      double Engine2FuelPressure; //Fuel Pressure of Engine #2 double psi
      bool APUOn;                 //APU On state 0=Off,1=on
      bool APUGenOn;              //APU Generator On, 0=Off,1=on
      bool APUAccumLo;            //APU Accumulator Low state, 0=off,1=Accumulator low
      double APUAccumPress;       //APU Accumulator Pressure [0-100]% nominal
      bool APUFail;               //APU Failure State, 0=off,1=Failure
      bool APUOilTp;              //APU Oil Temperature High, 0=off,1=Hot APU Oil on
      double APURPM;              //APU RPM
      double APUNp;               //APU Normalized speed in %
   };

   enum eNavSource
   {
      kNavVor = 0,
      kNavFms,
      kNavTcn,
      kNavPGR
   };

   enum eBearingSource
   {
      kBearingNone = 0,
      kBearingFms,
      kBearingVor,
      kBearingTcn,
      kBearingAdf,
      kBearingPgr
   };

   enum eReferenceSelect
   {
      kReferenceBaro = 0,
      kReferenceRaHigh,
      kReferenceRaLow,
      kReferenceFmsTime
   };

   static const char *PILOT_FDDCP = "CEPT_PILOT_FDDCP";
   static const char *COPILOT_FDDCP = "CEPT_COPILOT_FDDCP";
   struct FDDCP
   {
      bool pbcpld; //Push button Coupled/Uncoupled (Switch) boolean
      bool pbvs; //Push button Vertical Speed Hold (Switch) boolean
      bool pbhdg; //Push button Heading Hold (Switch) boolean
      bool pbias; //Push button Airspeed Hold (Switch) boolean
      bool pbalt; //Push button Altitude Hold (Switch) boolean
      bool pbaltp; //Push button Altitude Preselect (Switch) boolean
      bool pbralt; //Push button Radar Altimeter Hold (Switch) boolean
      bool pbgs; //Push button Glide Slope (Switch) boolean
      bool pbloc; //Push button localizer (TCN, VOR, FMS) (Switch) boolean
      bool pbgoarnd; //Push button Go Around Mode (Switch) boolean
      bool pbdecel; //Push button Deceleration mode (Switch) boolean
      bool pbhvr; //Push button Hover Hold Mode (Switch) boolean
      bool pbobs; //Push button OBS (Switch) boolean
      bool pbhdgsync; //Push button Heading Sync (Switch) boolean
      bool pbiassync; //Push button Indicated Airspeed Sync (Switch) boolean
      bool pbaltsync; //Push button Altitude Sync (Switch) boolean
      bool pbaltpsync; //Push button Altitude Preselect Sync (Switch) boolean
      bool pbraltsync; //Push button Radar Altitude Sync (Switch) boolean
      bool pbrefsync; //Push button Reference Value Sync (Switch) boolean
      double knobhdg; //Knob to change Heading Reference double clicks
      double knobias; //Knob to change Indicated Airspeed double clicks
      double knobalt; //Knob to change Altitude double clicks
      double knobaltp; //Knob to change Altitude Preselect double clicks
      double knobralt; //Knob to change Radar Altitude double clicks
      double knobref; //Knob to change Selected Reference value double clicks
      double knobobs; //Knob to change OBS value double clicks
      UINT8 navsrc; //Lateral navigation mode (FMS, TCN, VOR) uint8
      UINT8 refsrc; //Reference Selection (RA-LOW,RA-HIGH,BARO REF,FMS TIME) uint8
      UINT8 bearing1src; //Bearing 1 pointer source (OFF,FMS,VOR,TCN,ADF)
      UINT8 bearing2src; //Bearing 2 pointer source (OFF,FMS,VOR,TCN,ADF)
      INT16 raHigh; //Radar altitude high setting
      INT16 raLow; //Radar altitude low setting
      bool etadisp; //ETA display boolean
      double fmsroll; //FMS roll steering command double
   };

   static const char *PILOT_FMS = "CEPT_PILOT_FMS";
   static const char *COPILOT_FMS = "CEPT_COPILOT_FMS";
   struct FMS
   {
      UINT8 annunciatorLights;                  // annunciator lights [0x1=FMS,0x2=STS,0x4=MSG]
      UINT8 brightDimButton; // brightness/dimness rocker [0=NONE,1=UP,2=DOWN]
      UINT8 prvNxtButton; // previous/next rocker [0=NONE, 1=PREVIOUS, 2=NEXT]
      unsigned short softKeyMask; // key mask for soft keys and unused function keys f1, f2, f3, f4
      unsigned long long fixedFunctionKeyMask;  // key mask for other fixed function keys
   };
   static const UINT8 FMS_LIGHT_FMS = 0x1;
   static const UINT8 FMS_LIGHT_STS = 0x2;
   static const UINT8 FMS_LIGHT_MSG = 0x4;
   static const unsigned short FMS_SK1  = 0x1;
   static const unsigned short FMS_SK2  = 0x2;
   static const unsigned short FMS_SK3  = 0x4;
   static const unsigned short FMS_SK4  = 0x8;
   static const unsigned short FMS_SK5  = 0x10;
   static const unsigned short FMS_SK6  = 0x20;
   static const unsigned short FMS_SK7  = 0x40;
   static const unsigned short FMS_SK8  = 0x80;
   static const unsigned short FMS_SK9  = 0x100;
   static const unsigned short FMS_SK10 = 0x200;
   static const unsigned short FMS_F1   = 0x400;
   static const unsigned short FMS_F2   = 0x800;
   static const unsigned short FMS_F3   = 0x1000;
   static const unsigned short FMS_F4   = 0x2000;
   static const unsigned long long FMS_DIRECT_TO   = 0x1;
   static const unsigned long long FMS_IDNT        = 0x2;
   static const unsigned long long FMS_COM         = 0x4;
   static const unsigned long long FMS_NAV         = 0x8;
   static const unsigned long long FMS_EGI         = 0x10;
   static const unsigned long long FMS_FPN         = 0x20;
   static const unsigned long long FMS_DAT         = 0x40;
   static const unsigned long long FMS_CLC         = 0x80;
   static const unsigned long long FMS_FIX         = 0x100;
   static const unsigned long long FMS_MSN         = 0x200;
   static const unsigned long long FMS_CLR         = 0x400;
   static const unsigned long long FMS_XPD         = 0x800;
   static const unsigned long long FMS_INI         = 0x1000;
   static const unsigned long long FMS_ZRO         = 0x2000;
   static const unsigned long long FMS_STS         = 0x4000;
   static const unsigned long long FMS_TST         = 0x8000;
   static const unsigned long long FMS_PPS         = 0x10000;
   static const unsigned long long FMS_UP          = 0x20000;
   static const unsigned long long FMS_DOWN        = 0x40000;
   static const unsigned long long FMS_LEFT        = 0x80000;
   static const unsigned long long FMS_RIGHT       = 0x100000;
   static const unsigned long long FMS_ENT         = 0x200000;
   static const unsigned long long FMS_A           = 0x400000;
   static const unsigned long long FMS_B           = 0x800000;
   static const unsigned long long FMS_C           = 0x1000000;
   static const unsigned long long FMS_D           = 0x2000000;
   static const unsigned long long FMS_E           = 0x4000000;
   static const unsigned long long FMS_F           = 0x8000000;
   static const unsigned long long FMS_G           = 0x10000000;
   static const unsigned long long FMS_H           = 0x20000000;
   static const unsigned long long FMS_I           = 0x40000000;
   static const unsigned long long FMS_J           = 0x80000000;
   static const unsigned long long FMS_K           = 0x100000000;
   static const unsigned long long FMS_L           = 0x200000000;
   static const unsigned long long FMS_M           = 0x400000000;
   static const unsigned long long FMS_N           = 0x800000000;
   static const unsigned long long FMS_O           = 0x1000000000;
   static const unsigned long long FMS_P           = 0x2000000000;
   static const unsigned long long FMS_Q           = 0x4000000000;
   static const unsigned long long FMS_R           = 0x8000000000;
   static const unsigned long long FMS_S           = 0x10000000000;
   static const unsigned long long FMS_T           = 0x20000000000;
   static const unsigned long long FMS_U           = 0x40000000000;
   static const unsigned long long FMS_V           = 0x80000000000;
   static const unsigned long long FMS_W           = 0x100000000000;
   static const unsigned long long FMS_X           = 0x200000000000;
   static const unsigned long long FMS_Y           = 0x400000000000;
   static const unsigned long long FMS_Z           = 0x800000000000;
   static const unsigned long long FMS_1           = 0x1000000000000;
   static const unsigned long long FMS_2           = 0x2000000000000;
   static const unsigned long long FMS_3           = 0x4000000000000;
   static const unsigned long long FMS_4           = 0x8000000000000;
   static const unsigned long long FMS_5           = 0x10000000000000;
   static const unsigned long long FMS_6           = 0x20000000000000;
   static const unsigned long long FMS_7           = 0x40000000000000;
   static const unsigned long long FMS_8           = 0x80000000000000;
   static const unsigned long long FMS_9           = 0x100000000000000;
   static const unsigned long long FMS_0           = 0x200000000000000;
   static const unsigned long long FMS_SPC         = 0x400000000000000;
   static const unsigned long long FMS_PLUS_MINUS  = 0x800000000000000;
   static const unsigned long long FMS_PT          = 0x1000000000000000;

   static const char *MFD_1 = "MFD_1";
   static const char *MFD_2 = "MFD_2";
   static const char *MFD_3 = "MFD_3";
   static const char *MFD_4 = "MFD_4";
   struct MFD
   {
      bool powerSwitch;          //MFD on/off
      long keyMask;
      UINT8 backlightBrightness; // adjust backlight brightness [0=OFF, 1=UP, 2=DOWN]
      UINT8 videoBrightness;     // adjust video brightness [0=OFF, 1=UP, 2=DOWN]
      UINT8 videoContrast;       // adjust video brightness [0=OFF, 1=UP, 2=DOWN]
   };
   // mfd bezel button flags
   static const long MFD_BB1 = 0x1;
   static const long MFD_BB2 = 0x2;
   static const long MFD_BB3 = 0x4;
   static const long MFD_BB4 = 0x8;
   static const long MFD_BB5 = 0x10;
   static const long MFD_BB6 = 0x20;
   static const long MFD_BL1 = 0x40;
   static const long MFD_BL2 = 0x80;
   static const long MFD_BL3 = 0x100;
   static const long MFD_BL4 = 0x200;
   static const long MFD_BL5 = 0x400;
   static const long MFD_BL6 = 0x800;
   static const long MFD_BR1 = 0x1000;
   static const long MFD_BR2 = 0x2000;
   static const long MFD_BR3 = 0x4000;
   static const long MFD_BR4 = 0x8000;
   static const long MFD_BR5 = 0x10000;
   static const long MFD_BR6 = 0x20000;
   static const long MFD_BT1 = 0x40000;
   static const long MFD_BT2 = 0x80000;
   static const long MFD_BT3 = 0x100000;
   static const long MFD_BT4 = 0x2000000;
   static const long MFD_BT5 = 0x4000000;
   static const long MFD_BT6 = 0x8000000;

   static const char *FCC1_FCC2FDDCP = "FCC1_FCC2FDDCP";
   static const char *FCC2_FCC2FDDCP = "FCC2_FCC2FDDCP";

   // FCC2FDDCP represents data sent from the FCC to the FDDCP.
   struct FCC2FDDCP
   {
      // station 1 coupled display characters (decimal ascii code)
      unsigned char buf01ch1;
      unsigned char buf01ch2;
      unsigned char buf01ch3;
      unsigned char buf01ch4;
      unsigned char buf01ch5;
      unsigned char buf01ch6;
      unsigned char buf01ch7;
      unsigned char buf01ch8;
      // station 2 vertical speed display characters (decimal ascii code)
      unsigned char buf02ch1;
      unsigned char buf02ch2;
      unsigned char buf02ch3;
      unsigned char buf02ch4;
      unsigned char buf02ch5;
      unsigned char buf02ch6;
      unsigned char buf02ch7;
      unsigned char buf02ch8;
      // station 3 heading display characters (decimal ascii code)
      unsigned char buf03ch1;
      unsigned char buf03ch2;
      unsigned char buf03ch3;
      unsigned char buf03ch4;
      unsigned char buf03ch5;
      unsigned char buf03ch6;
      unsigned char buf03ch7;
      unsigned char buf03ch8;
      // station 4 airspeed display characters (decimal ascii code)
      unsigned char buf04ch1;
      unsigned char buf04ch2;
      unsigned char buf04ch3;
      unsigned char buf04ch4;
      unsigned char buf04ch5;
      unsigned char buf04ch6;
      unsigned char buf04ch7;
      unsigned char buf04ch8;
      // station 5 baro altitude display characters (decimal ascii code)
      unsigned char buf05ch1;
      unsigned char buf05ch2;
      unsigned char buf05ch3;
      unsigned char buf05ch4;
      unsigned char buf05ch5;
      unsigned char buf05ch6;
      unsigned char buf05ch7;
      unsigned char buf05ch8;
      // station 6 altitude preselect display characters (decimal ascii code)
      unsigned char buf06ch1;
      unsigned char buf06ch2;
      unsigned char buf06ch3;
      unsigned char buf06ch4;
      unsigned char buf06ch5;
      unsigned char buf06ch6;
      unsigned char buf06ch7;
      unsigned char buf06ch8;
      // station 7 radar altitude display characters (decimal ascii code)
      unsigned char buf07ch1;
      unsigned char buf07ch2;
      unsigned char buf07ch3;
      unsigned char buf07ch4;
      unsigned char buf07ch5;
      unsigned char buf07ch6;
      unsigned char buf07ch7;
      unsigned char buf07ch8;
      // station 8 vertical navigation display characters (decimal ascii code)
      unsigned char buf08ch1;
      unsigned char buf08ch2;
      unsigned char buf08ch3;
      unsigned char buf08ch4;
      unsigned char buf08ch5;
      unsigned char buf08ch6;
      unsigned char buf08ch7;
      unsigned char buf08ch8;
      // station 9 roll navigation display characters (decimal ascii code)
      unsigned char buf09ch1;
      unsigned char buf09ch2;
      unsigned char buf09ch3;
      unsigned char buf09ch4;
      unsigned char buf09ch5;
      unsigned char buf09ch6;
      unsigned char buf09ch7;
      unsigned char buf09ch8;
      // station 14 go around display characters (decimal ascii code)
      unsigned char buf14ch1;
      unsigned char buf14ch2;
      unsigned char buf14ch3;
      unsigned char buf14ch4;
      unsigned char buf14ch5;
      unsigned char buf14ch6;
      unsigned char buf14ch7;
      unsigned char buf14ch8;
      // station 15 decel display characters (decimal ascii code)
      unsigned char buf15ch1;
      unsigned char buf15ch2;
      unsigned char buf15ch3;
      unsigned char buf15ch4;
      unsigned char buf15ch5;
      unsigned char buf15ch6;
      unsigned char buf15ch7;
      unsigned char buf15ch8;
      // station 16 hover display characters (decimal ascii code)
      unsigned char buf16ch1;
      unsigned char buf16ch2;
      unsigned char buf16ch3;
      unsigned char buf16ch4;
      unsigned char buf16ch5;
      unsigned char buf16ch6;
      unsigned char buf16ch7;
      unsigned char buf16ch8;
      // station 17 hover display characters (decimal ascii code)
      unsigned char buf17ch1;
      unsigned char buf17ch2;
      unsigned char buf17ch3;
      unsigned char buf17ch4;
      unsigned char buf17ch5;
      unsigned char buf17ch6;
      unsigned char buf17ch7;
      unsigned char buf17ch8;

      // station led status (0=off, 1=green, 2=amber)
      UINT8 ledout01;
      UINT8 ledout02;
      UINT8 ledout03;
      UINT8 ledout04;
      UINT8 ledout05;
      UINT8 ledout06;
      UINT8 ledout07;
      UINT8 ledout08;
      UINT8 ledout09;
      UINT8 ledout14;
      UINT8 ledout15;
      UINT8 ledout16;
	  UINT8 ledout17;
   };

   static const char *FCC1_FCC2MFD = "FCC1_FCC2MFD";
   static const char *FCC2_FCC2MFD = "FCC2_FCC2MFD";

   // FCC2MFD represents data sent from the FCC to the MFD.
   struct FCC2MFD
   {
      // FD references
      double vsref;     // vertical speed reference (fpm, +up)
      double iasref;    // airspeed reference (kts)
      double baltref;   // baro altitude reference (ft)
      double altpref;   // altitude preselect reference (ft)
      double raltref;   // radar altitude reference (ft)
      double xvelref;   // x-velocity reference (kts)
      double yvelref;   // y-velocity reference (kts)
      double hdgref;    // Selected heading reference (deg)

      // FD pilot cues displayed on MFD HSI and VSI
      double fdrcue;    // FD roll cue (deg)
      double fdpcue;    // FD pitch cue (deg)
      double fdccue;    // FD collective cue (%)

      // FD references
      bool vsrefdisp;   // vertical speed reference display
      bool iasrefdisp;  // airspeed reference display
      bool baltrefdisp; // baro altitude reference display
      bool altprefdisp; // altitude preselect reference display
      bool raltrefdisp; // radar altitude reference display
      bool xvelrefdisp; // x-velocity reference display
      bool yvelrefdisp; // y-velocity reference display
      bool hdgrefdisp;  // heading reference display

      // FD pilot cues displayed on MFD HSI and VSI
      bool fdrcuedisp;  // FD roll cue display
      bool fdpcuedisp;  // FD pitch cue display
      bool fdccuedisp;  // FD collective cue display

      // FD coupled and mode engage states
      bool fd1sel;      // FD 1 coupled
      bool fd2sel;      // FD 2 coupled
      bool locarm;      // FD localizer mode armed
      bool loccap;      // FD localizer mode captured
      bool bceng;       // FD back course engaged
      bool bcarm;       // FD back course mode armed
      bool bccap;       // FD back course mode captured
      bool navarm;      // FD vor/tacan mode armed
      bool navcap;      // FD vor/tacan mode captured
      bool lnavcap;     // FD flight plan navigation captured
      bool glideslopearm; // FD glideslope mode armed
      bool glideslopecap; // FD glideslope mode captured
      bool declarm;     // FD decel mode armed
      bool declcap;     // FD decel mode captured
      bool vseng;       // FD vertical speed mode engaged
      bool selhdgeng;   // FD select heading mode engaged
      bool iaseng;      // FD airspeed mode engaged
      bool balteng;     // FD baro altitude mode engaged
      bool altparm;     // FD altitude preselect mode armed
      bool altpcap;     // FD altitude preselect mode captured
      bool ralteng;     // FD radar altitude mode engaged
      bool gaeng;       // FD go around mode engaged
      bool vhvreng;     // FD velocity hover mode engaged
      bool phvreng;     // FD position hover mode engaged
   };

   static const char *PILOT_MFSC = "CEPT_PILOT_MFSC";
   static const char *COPILOT_MFSC = "CEPT_COPILOT_MFSC";
   struct Mfsc
   {
      bool Select;    // Select button
      bool Menu;      // Menu button
      bool Mode;      // Mode button
      double RateX;   // Cursor x position
      double RateY;   // Cursor y position
   };

   static const char *FLIR = "CEPT_FLIR";
   struct Flir
   {
      bool FlirValid;   // Flir Controler Found/Valid
      bool FreezeFrame; // freeze frame selection
      bool Hook;        // hook selection
      bool Menu;        // menu selection
      bool Lock;        // lock selection
      bool Stow;        // stow selection
      bool IP_HH;       // IP/HH selection
      bool FocusIn;     // focus in selection
      bool Cage;        // cage selection
      bool FocusOut;    // Focus Out selection
      bool POL_AF;      // POL/AF selection
      bool LevelUp;     // level up selection
      bool GainDown;    // gain down selection
      bool LevelDown;   // level down selection
      bool GainUp;      // gain up selection
      bool AutoGain;    // auto gain selection
      bool Power;       // power switch
      UINT8 Trigger;    // [0=CENTER, 1=UP, 2=DOWN]
      UINT8 AuxSwitch;  // [0=CENTER, 1=FORWARD, 2=BACK]
      double RateX;   // Cursor x position
      double RateY;   // Cursor y position
   };

   enum eLoaderChannelState
   {
      kChannelFailed = 0,
      kChannelStandby,
      kChannelActive
   };

   static const char *CONTROL_LOADER = "CONTROL_LOADER";
   struct ControlLoaderChannelStatus
   {
      UINT8 PitchChannelStatus;
      UINT8 RollChannelStatus;
      UINT8 YawChannelStatus;
      UINT8 CollectiveChannelStatus;
   };

   static const char *TEST_DATA = "CEPT_TEST_DATA";
   struct TestData
   {
      //10 boolean test variables
      bool test_1;
      bool test_2;
      bool test_3;
      bool test_4;
      bool test_5;
      bool test_6;
      bool test_7;
      bool test_8;
      bool test_9;
      bool test_10;
      //10 double test variables
      double test_11;
      double test_12;
      double test_13;
      double test_14;
      double test_15;
      double test_16;
      double test_17;
      double test_18;
      double test_19;
      double test_20;
   };
}