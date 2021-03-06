/* TRANSACT.C   (C) Copyright "Fish" (David B. Trout), 2017          */
/*      Defines Transactional Execution Facility instructions        */
/*                                                                   */
/*   Released under "The Q Public License Version 1"                 */
/*   (http://www.hercules-390.org/herclic.html)                      */
/*   as modifications to Hercules.                                   */

/*********************************************************************/

#include "hstdinc.h"

#define _TRANSACT_C_
#define _HENGINE_DLL_

#include "hercules.h"
#include "opcode.h"
#include "inline.h"

DISABLE_GCC_UNUSED_SET_WARNING;

/*-------------------------------------------------------------------*/
/*                      (BEGIN static helpers)                       */
/*                      (CANNOT BE ARCH_DEP!!)                       */
/*-------------------------------------------------------------------*/

#if !defined( COMPILE_THIS_ONLY_ONCE )
#define       COMPILE_THIS_ONLY_ONCE

/*-------------------------------------------------------------------*/
/* static helper function 1 ...                                      */
/*-------------------------------------------------------------------*/
//static void static_helper_1()
//{
//    // TODO...
//}

/*-------------------------------------------------------------------*/
/* static helper function 2 ...                                      */
/*-------------------------------------------------------------------*/
//static int static_helper_2()
//{
//    // TODO...
//    return 0;
//}

/*-------------------------------------------------------------------*/
#endif /*            (end COMPILE_THIS_ONLY_ONCE)                    */
/*-------------------------------------------------------------------*/

/*-------------------------------------------------------------------*/
/*                  (begin ARCH_DEP static helpers)                  */
/*-------------------------------------------------------------------*/

/*-------------------------------------------------------------------*/
/* ARCH_DEP helper function 1 ...                                    */
/*-------------------------------------------------------------------*/
//static void ARCH_DEP( arch_helper_1 )()
//{
//    // TODO...
//}

/*-------------------------------------------------------------------*/
/* ARCH_DEP helper function 2 ...                                    */
/*-------------------------------------------------------------------*/
//static int ARCH_DEP( arch_helper_2 )()
//{
//    // TODO...
//    return 0;
//}

/*-------------------------------------------------------------------*/
/*                   (end ARCH_DEP static helpers)                   */
/*-------------------------------------------------------------------*/

#if defined( FEATURE_049_PROCESSOR_ASSIST_FACILITY )

#define PPA_MAX_HELP_THRESHOLD  16
#define PPA_MED_HELP_THRESHOLD   8
#define PPA_MIN_HELP_THRESHOLD   1

/*-------------------------------------------------------------------*/
/* B2E8 PPA   - Perform Processor Assist                     [RRF-c] */
/*-------------------------------------------------------------------*/
DEF_INST( perform_processor_assist )
{
int     r1, r2;                         /* Operand register numbers  */
int     m3;                             /* M3 Mask value             */
U32     abort_count;                    /* Transaction Abort count   */

    RRF_M( inst, regs, r1, r2, m3 );

    /* Retrieve abort count */
    abort_count = regs->GR_L( r1 );

    switch (m3)
    {
    case 1: // Transaction Abort Assist
    {
        /* Provide least amount of assistance required */
        if (abort_count >= PPA_MAX_HELP_THRESHOLD)
        {
            /* Provide maximal assistance */
            // TODO... do something useful
        }
        else if (abort_count >= PPA_MED_HELP_THRESHOLD)
        {
            /* Provide medium assistance */
            // TODO... do something useful
        }
        else if (abort_count >= PPA_MIN_HELP_THRESHOLD)
        {
            /* Provide minimal assistance */
            // TODO... do something useful
        }
        else // zero!
        {
            /* Provide NO assistance at all */
            // (why are you wasting my time?!)
        }
        return;
    }

    default:     /* (unknown/unsupported assist) */
        return;  /* (ignore unsupported assists) */
    }

    UNREACHABLE_CODE( return );

} /* end DEF_INST( perform_processor_assist ) */
#endif /* defined( FEATURE_049_PROCESSOR_ASSIST_FACILITY ) */


#if defined( FEATURE_073_TRANSACT_EXEC_FACILITY )

/*-------------------------------------------------------------------*/
/* B2EC ETND  - Extract Transaction Nesting Depth              [RRE] */
/*-------------------------------------------------------------------*/
DEF_INST( extract_transaction_nesting_depth )
{
int     r1, r2;                         /* Operand register numbers  */

    RRE( inst, regs, r1, r2 );

    // TODO....

} /* end DEF_INST( extract_transaction_nesting_depth ) */


/*-------------------------------------------------------------------*/
/* B2F8 TEND - Transaction End                                   [S] */
/*-------------------------------------------------------------------*/
DEF_INST( transaction_end )
{
int     b2;                             /* Base of effective addr    */
VADR    effective_addr2;                /* Effective address         */

    S( inst, regs, b2, effective_addr2 );

    // TODO....

} /* end DEF_INST( transaction_end ) */


/*-------------------------------------------------------------------*/
/* B2FC TABORT - Transaction Abort                               [S] */
/*-------------------------------------------------------------------*/
DEF_INST( transaction_abort )
{
int     b2;                             /* Base of effective addr    */
VADR    effective_addr2;                /* Effective address         */

    S( inst, regs, b2, effective_addr2 );

    // TODO....

} /* end DEF_INST( transaction_abort ) */


/*-------------------------------------------------------------------*/
/* E325 NTSTG - Nontransactional Store                       [RXY-a] */
/*-------------------------------------------------------------------*/
DEF_INST( nontransactional_store )
{
int     r1;                             /* Value of R1 field         */
int     b2;                             /* Base of effective addr    */
VADR    effective_addr2;                /* Effective address         */

    RXY( inst, regs, r1, b2, effective_addr2 );

    // TODO....

} /* end DEF_INST( nontransactional_store ) */


/*-------------------------------------------------------------------*/
/* E560 TBEGIN - Transaction Begin  (unconstrained)            [SIL] */
/*-------------------------------------------------------------------*/
DEF_INST( transaction_begin )
{
S16     i2;                             /* 16-bit immediate value    */
int     b1;                             /* Base of effective addr    */
VADR    effective_addr1;                /* Effective address         */

    SIL( inst, regs, i2, b1, effective_addr1 );

    // TODO....

} /* end DEF_INST( transaction_begin ) */


#if defined( FEATURE_050_CONSTR_TRANSACT_FACILITY )
/*-------------------------------------------------------------------*/
/* E561 TBEGINC - Transaction Begin  (CONSTRAINED)             [SIL] */
/*-------------------------------------------------------------------*/
DEF_INST( transaction_begin_constrained )
{
S16     i2;                             /* 16-bit immediate value    */
int     b1;                             /* Base of effective addr    */
VADR    effective_addr1;                /* Effective address         */

    SIL( inst, regs, i2, b1, effective_addr1 );

    // TODO....

} /* end DEF_INST( transaction_begin_constrained ) */
#endif /* defined( FEATURE_050_CONSTR_TRANSACT_FACILITY ) */
#endif /* defined( FEATURE_073_TRANSACT_EXEC_FACILITY ) */


#if !defined(_GEN_ARCH)

#if defined(_ARCH_NUM_1)
  #define  _GEN_ARCH _ARCH_NUM_1
  #include "transact.c"
#endif

#if defined(_ARCH_NUM_2)
  #undef   _GEN_ARCH
  #define  _GEN_ARCH _ARCH_NUM_2
  #include "transact.c"
#endif

#endif /*!defined(_GEN_ARCH)*/
