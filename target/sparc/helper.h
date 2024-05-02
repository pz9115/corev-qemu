#ifndef TARGET_SPARC64
DEF_HELPER_1(rett, void, env)
DEF_HELPER_2(wrpsr, void, env, tl)
DEF_HELPER_1(rdpsr, tl, env)
DEF_HELPER_1(rdasr17, tl, env)
DEF_HELPER_1(power_down, void, env)
#else
DEF_HELPER_FLAGS_2(wrpil, TCG_CALL_NO_RWG, void, env, tl)
DEF_HELPER_2(wrgl, void, env, tl)
DEF_HELPER_2(wrpstate, void, env, tl)
DEF_HELPER_1(done, void, env)
DEF_HELPER_1(retry, void, env)
DEF_HELPER_FLAGS_1(flushw, TCG_CALL_NO_WG, void, env)
DEF_HELPER_FLAGS_1(saved, TCG_CALL_NO_RWG, void, env)
DEF_HELPER_FLAGS_1(restored, TCG_CALL_NO_RWG, void, env)
DEF_HELPER_1(rdccr, tl, env)
DEF_HELPER_2(wrccr, void, env, tl)
DEF_HELPER_1(rdcwp, tl, env)
DEF_HELPER_2(wrcwp, void, env, tl)
DEF_HELPER_FLAGS_2(array8, TCG_CALL_NO_RWG_SE, tl, tl, tl)
DEF_HELPER_FLAGS_2(set_softint, TCG_CALL_NO_RWG, void, env, i64)
DEF_HELPER_FLAGS_2(clear_softint, TCG_CALL_NO_RWG, void, env, i64)
DEF_HELPER_FLAGS_2(write_softint, TCG_CALL_NO_RWG, void, env, i64)
DEF_HELPER_FLAGS_2(tick_set_count, TCG_CALL_NO_RWG, void, ptr, i64)
DEF_HELPER_FLAGS_3(tick_get_count, TCG_CALL_NO_WG, i64, env, ptr, int)
DEF_HELPER_FLAGS_2(tick_set_limit, TCG_CALL_NO_RWG, void, ptr, i64)
#endif
DEF_HELPER_1(debug, void, env)
DEF_HELPER_1(save, void, env)
DEF_HELPER_1(restore, void, env)
DEF_HELPER_FLAGS_3(udiv, TCG_CALL_NO_WG, i64, env, tl, tl)
DEF_HELPER_FLAGS_3(sdiv, TCG_CALL_NO_WG, i64, env, tl, tl)
DEF_HELPER_3(taddcctv, tl, env, tl, tl)
DEF_HELPER_3(tsubcctv, tl, env, tl, tl)
#if !defined(CONFIG_USER_ONLY) && !defined(TARGET_SPARC64)
DEF_HELPER_FLAGS_3(ld_code, TCG_CALL_NO_WG, i64, env, tl, i32)
#endif
#if !defined(CONFIG_USER_ONLY) || defined(TARGET_SPARC64)
DEF_HELPER_FLAGS_4(ld_asi, TCG_CALL_NO_WG, i64, env, tl, int, i32)
DEF_HELPER_FLAGS_5(st_asi, TCG_CALL_NO_WG, void, env, tl, i64, int, i32)
#endif
DEF_HELPER_FLAGS_1(get_fsr, TCG_CALL_NO_WG_SE, tl, env)
DEF_HELPER_FLAGS_2(set_fsr_nofcc_noftt, TCG_CALL_NO_RWG, void, env, i32)
DEF_HELPER_FLAGS_2(fsqrts, TCG_CALL_NO_WG, f32, env, f32)
DEF_HELPER_FLAGS_2(fsqrtd, TCG_CALL_NO_WG, f64, env, f64)
DEF_HELPER_FLAGS_2(fsqrtq, TCG_CALL_NO_WG, i128, env, i128)
DEF_HELPER_FLAGS_3(fcmps, TCG_CALL_NO_WG, i32, env, f32, f32)
DEF_HELPER_FLAGS_3(fcmpes, TCG_CALL_NO_WG, i32, env, f32, f32)
DEF_HELPER_FLAGS_3(fcmpd, TCG_CALL_NO_WG, i32, env, f64, f64)
DEF_HELPER_FLAGS_3(fcmped, TCG_CALL_NO_WG, i32, env, f64, f64)
DEF_HELPER_FLAGS_3(fcmpq, TCG_CALL_NO_WG, i32, env, i128, i128)
DEF_HELPER_FLAGS_3(fcmpeq, TCG_CALL_NO_WG, i32, env, i128, i128)
DEF_HELPER_2(raise_exception, noreturn, env, int)

DEF_HELPER_FLAGS_3(faddd, TCG_CALL_NO_WG, f64, env, f64, f64)
DEF_HELPER_FLAGS_3(fsubd, TCG_CALL_NO_WG, f64, env, f64, f64)
DEF_HELPER_FLAGS_3(fmuld, TCG_CALL_NO_WG, f64, env, f64, f64)
DEF_HELPER_FLAGS_3(fdivd, TCG_CALL_NO_WG, f64, env, f64, f64)

DEF_HELPER_FLAGS_3(faddq, TCG_CALL_NO_WG, i128, env, i128, i128)
DEF_HELPER_FLAGS_3(fsubq, TCG_CALL_NO_WG, i128, env, i128, i128)
DEF_HELPER_FLAGS_3(fmulq, TCG_CALL_NO_WG, i128, env, i128, i128)
DEF_HELPER_FLAGS_3(fdivq, TCG_CALL_NO_WG, i128, env, i128, i128)

DEF_HELPER_FLAGS_3(fadds, TCG_CALL_NO_WG, f32, env, f32, f32)
DEF_HELPER_FLAGS_3(fsubs, TCG_CALL_NO_WG, f32, env, f32, f32)
DEF_HELPER_FLAGS_3(fmuls, TCG_CALL_NO_WG, f32, env, f32, f32)
DEF_HELPER_FLAGS_3(fdivs, TCG_CALL_NO_WG, f32, env, f32, f32)

DEF_HELPER_FLAGS_3(fsmuld, TCG_CALL_NO_WG, f64, env, f32, f32)
DEF_HELPER_FLAGS_3(fdmulq, TCG_CALL_NO_WG, i128, env, f64, f64)

DEF_HELPER_FLAGS_2(fitod, TCG_CALL_NO_WG, f64, env, s32)
DEF_HELPER_FLAGS_2(fitoq, TCG_CALL_NO_WG, i128, env, s32)

DEF_HELPER_FLAGS_2(fitos, TCG_CALL_NO_WG, f32, env, s32)

#ifdef TARGET_SPARC64
DEF_HELPER_FLAGS_2(fxtos, TCG_CALL_NO_WG, f32, env, s64)
DEF_HELPER_FLAGS_2(fxtod, TCG_CALL_NO_WG, f64, env, s64)
DEF_HELPER_FLAGS_2(fxtoq, TCG_CALL_NO_WG, i128, env, s64)
#endif
DEF_HELPER_FLAGS_2(fdtos, TCG_CALL_NO_WG, f32, env, f64)
DEF_HELPER_FLAGS_2(fstod, TCG_CALL_NO_WG, f64, env, f32)
DEF_HELPER_FLAGS_2(fqtos, TCG_CALL_NO_WG, f32, env, i128)
DEF_HELPER_FLAGS_2(fstoq, TCG_CALL_NO_WG, i128, env, f32)
DEF_HELPER_FLAGS_2(fqtod, TCG_CALL_NO_WG, f64, env, i128)
DEF_HELPER_FLAGS_2(fdtoq, TCG_CALL_NO_WG, i128, env, f64)
DEF_HELPER_FLAGS_2(fstoi, TCG_CALL_NO_WG, s32, env, f32)
DEF_HELPER_FLAGS_2(fdtoi, TCG_CALL_NO_WG, s32, env, f64)
DEF_HELPER_FLAGS_2(fqtoi, TCG_CALL_NO_WG, s32, env, i128)
#ifdef TARGET_SPARC64
DEF_HELPER_FLAGS_2(fstox, TCG_CALL_NO_WG, s64, env, f32)
DEF_HELPER_FLAGS_2(fdtox, TCG_CALL_NO_WG, s64, env, f64)
DEF_HELPER_FLAGS_2(fqtox, TCG_CALL_NO_WG, s64, env, i128)

DEF_HELPER_FLAGS_2(fpmerge, TCG_CALL_NO_RWG_SE, i64, i64, i64)
DEF_HELPER_FLAGS_2(fmul8x16, TCG_CALL_NO_RWG_SE, i64, i32, i64)
DEF_HELPER_FLAGS_2(fmul8x16a, TCG_CALL_NO_RWG_SE, i64, i32, s32)
DEF_HELPER_FLAGS_2(fmul8sux16, TCG_CALL_NO_RWG_SE, i64, i64, i64)
DEF_HELPER_FLAGS_2(fmul8ulx16, TCG_CALL_NO_RWG_SE, i64, i64, i64)
DEF_HELPER_FLAGS_1(fexpand, TCG_CALL_NO_RWG_SE, i64, i32)
DEF_HELPER_FLAGS_3(pdist, TCG_CALL_NO_RWG_SE, i64, i64, i64, i64)
DEF_HELPER_FLAGS_2(fpack16, TCG_CALL_NO_RWG_SE, i32, i64, i64)
DEF_HELPER_FLAGS_3(fpack32, TCG_CALL_NO_RWG_SE, i64, i64, i64, i64)
DEF_HELPER_FLAGS_2(fpackfix, TCG_CALL_NO_RWG_SE, i32, i64, i64)
DEF_HELPER_FLAGS_3(bshuffle, TCG_CALL_NO_RWG_SE, i64, i64, i64, i64)
#define VIS_CMPHELPER(name)                                              \
    DEF_HELPER_FLAGS_2(f##name##16, TCG_CALL_NO_RWG_SE,      \
                       i64, i64, i64)                                    \
    DEF_HELPER_FLAGS_2(f##name##32, TCG_CALL_NO_RWG_SE,      \
                       i64, i64, i64)
VIS_CMPHELPER(cmpgt)
VIS_CMPHELPER(cmpeq)
VIS_CMPHELPER(cmple)
VIS_CMPHELPER(cmpne)
#endif
#undef VIS_HELPER
#undef VIS_CMPHELPER
