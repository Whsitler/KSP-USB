/**
 * \file
 *
 * \brief User board initialization template
 *
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>

void board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */
	XMEGACLK_StartExternalOscillator(EXOSC_FREQ_12MHZ_MAX, EXOSC_START_32KCLK);
	XMEGACLK_StartPLL(CLOCK_SRC_XOSC, 12000000, F_CPU);
	XMEGACLK_SetCPUClockSource(CLOCK_SRC_PLL);
	
	XMEGACLK_StartInternalOscillator(CLOCK_SRC_INT_RC32MHZ);
	XMEGACLK_StartDFLL(CLOCK_SRC_INT_RC32MHZ, DFLL_REF_INT_USBSOF, F_USB);
}
