#include <Arduino.h>
#include <NmraDcc.h>

// Library default defines, they must be inserted in main BEFORE including this library
#ifndef INVERT_DIRECTION
//#define INVERT_DIRECTION
#endif
#ifndef SET_LAST_SAVED_POSITION
//#define SET_LAST_SAVED_POSITION
#endif
#ifndef TASTER_COMMAND
//#define TASTER_COMMAND
#endif
#ifndef PULSING_OUTPUTS
//#define PULSING_OUTPUTS
#endif
#ifndef LOCONET_USB_COM
//#define LOCONET_USB_COM
#endif
#ifndef USE_MULTIPLE_ADDRESS
//#define USE_MULTIPLE_ADDRESS
#endif

#ifndef CONF_CV
	#define CONF_CV 28
#endif

// Mask
#define CV_X_INV_DIR     0b00000001
#define CV_X_SAVE_POS    0b00000010
#define CV_X_EN_TASTER   0b00000100
#define CV_X_PULSE       0b00001000
#define CV_X_EN_LN_USB   0b00010000
#define CV_X_MULTI_ADR   0b00100000

// Combinator
#if defined(INVERT_DIRECTION)
	#if defined(SET_LAST_SAVED_POSITION)
		#if defined(TASTER_COMMAND)
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_TASTER)
					#endif
				#endif
			#endif
		#else
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_SAVE_POS)
					#endif
				#endif
			#endif
		#endif
	#else
		#if defined(TASTER_COMMAND)
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER | CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER | CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_TASTER)
					#endif
				#endif
			#endif
		#else
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_INV_DIR | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_INV_DIR)
					#endif
				#endif
			#endif
		#endif
	#endif
#else
	#if defined(SET_LAST_SAVED_POSITION)
		#if defined(TASTER_COMMAND)
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_TASTER)
					#endif
				#endif
			#endif
		#else
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_SAVE_POS)
					#endif
				#endif
			#endif
		#endif
	#else
		#if defined(TASTER_COMMAND)
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER | CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER | CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER | CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_EN_TASTER)
					#endif
				#endif
			#endif
		#else
			#if defined(PULSING_OUTPUTS)
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_PULSE | CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_PULSE | CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_PULSE | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_PULSE)
					#endif
				#endif
			#else
				#if defined(LOCONET_USB_COM)
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_EN_LN_USB | CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (CV_X_EN_LN_USB)
					#endif
				#else
					#if defined(USE_MULTIPLE_ADDRESS)
						#define CONF_CV_DEFAULT (CV_X_MULTI_ADR)
					#else
						#define CONF_CV_DEFAULT (0)
					#endif
				#endif
			#endif
		#endif
	#endif
#endif


class confCV {
private:
	NmraDcc Dcc;
	uint8_t conf_cv = CONF_CV;
	bool INV = false;
	bool SAVE = false;
	bool TASTER = false;
	bool PULSE = false;
	bool LN_USB = false;
	bool MULTI_ADR = false;
public:
	confCV(NmraDcc DCC);
	void init(uint8_t CV);
	void init();
	bool GetInv(void);
	bool GetSave(void);
	bool GetTaster(void);
	bool GetPulse(void);
	bool GetLnUSB(void);
	bool GetMultiAdr(void);
	void SetInv(uint8_t val);
	void SetSave(uint8_t val);
	void SetTaster(uint8_t val);
	void SetPulse(uint8_t val);
	void SetLnUSB(uint8_t val);
	void SetMultiAdr(uint8_t val);
};

confCV::confCV(NmraDcc DCC){
  Dcc = DCC;
}

// initialize with custome CV
void confCV::init(uint8_t CV){
  conf_cv = CV;
  confCV::init();
}

// initialize
void confCV::init(void){
  INV = false;
  SAVE = false;
  TASTER = false;
  PULSE = false;
  LN_USB = false;
  MULTI_ADR = false;
  uint8_t CV_X = Dcc.getCV( conf_cv );
  if( CV_X & CV_X_INV_DIR )   INV = true;
  if( CV_X & CV_X_SAVE_POS )  SAVE = true;
  if( CV_X & CV_X_EN_TASTER ) TASTER = true;
  if( CV_X & CV_X_PULSE ) 	  PULSE = true;
  if( CV_X & CV_X_EN_LN_USB ) LN_USB = true;
  if( CV_X & CV_X_MULTI_ADR ) MULTI_ADR = true;
}

bool confCV::GetInv(void) {
  return INV;
}

bool confCV::GetSave(void) {
  return SAVE;
}

bool confCV::GetTaster(void) {
  return TASTER;
}

bool confCV::GetPulse(void) {
  return PULSE;
}

bool confCV::GetLnUSB(void) {
  return LN_USB;
}

bool confCV::GetMultiAdr(void) {
  return MULTI_ADR;
}

void confCV::SetInv(uint8_t val) {
  if (val)
	INV = true;
  else
	INV = false;
}

void confCV::SetSave(uint8_t val) {
  if (val)
	SAVE = true;
  else
	SAVE = false;
}

void confCV::SetTaster(uint8_t val) {
  if (val)
	TASTER = true;
  else
	TASTER = false;
}

void confCV::SetPulse(uint8_t val) {
  if (val)
	PULSE = true;
  else
	PULSE = false;
}

void confCV::SetLnUSB(uint8_t val) {
  if (val)
	LN_USB = true;
  else
	LN_USB = false;
}

void confCV::SetMultiAdr(uint8_t val) {
  if (val)
	MULTI_ADR = true;
  else
	MULTI_ADR = false;
}