#include "aubio_ffi.h"

// A very short-lived native function.
//
// For very short-lived functions, it is fine to call them on the main isolate.
// They will block the Dart execution while running the native function, so
// only do this for native functions which are guaranteed to be short-lived.
FFI_PLUGIN_EXPORT intptr_t sum(intptr_t a, intptr_t b) { return a + b; }

// A longer-lived native function, which occupies the thread calling it.
//
// Do not call these kind of native functions in the main isolate. They will
// block Dart execution. This will cause dropped frames in Flutter applications.
// Instead, call these native functions on a separate isolate.
FFI_PLUGIN_EXPORT intptr_t sum_long_running(intptr_t a, intptr_t b) {
  // Simulate work.
#if _WIN32
  Sleep(5000);
#else
  usleep(5000 * 1000);
#endif
  return a + b;
}

#define HAVE_STDLIB_H
#define HAVE_MATH_H
#define HAVE_STDIO_H
#define HAVE_COMPLEX_H
#define HAVE_STRING_H
#define HAVE_ERRNO_H
#define HAVE_LIMITS_H
#define HAVE_STDARG_H
#include "musicutils.c"
#include "pitch/pitchspecacf.c"
#include "pitch/pitchyin.h"
#include "pitch/pitch.h"
#include "pitch/pitchschmitt.c"
#include "pitch/pitchmcomb.c"
#include "pitch/pitchyinfast.c"
#include "pitch/pitchfcomb.h"
#include "pitch/pitchyinfft.h"
#include "pitch/pitchyin.c"
#include "pitch/pitchspecacf.h"
#include "pitch/pitch.c"
#include "pitch/pitchschmitt.h"
#include "pitch/pitchfcomb.c"
#include "pitch/pitchyinfast.h"
#include "pitch/pitchmcomb.h"
#include "pitch/pitchyinfft.c"
#include "temporal/a_weighting.h"
#include "temporal/resampler.c"
#include "temporal/biquad.h"
#include "temporal/c_weighting.c"
#include "temporal/filter.c"
#include "temporal/a_weighting.c"
#include "temporal/resampler.h"
#include "temporal/biquad.c"
#include "temporal/c_weighting.h"
#include "temporal/filter.h"
#include "cvec.h"
#include "fmat.c"
#include "fvec.c"
#include "types.h"
#include "aubio.h"
#include "vecutils.c"
#include "io/sink_vorbis.c"
#include "io/sink.c"
#include "io/audio_unit.h"
#include "io/source_wavread.h"
#include "io/ioutils.h"
#include "io/sink_sndfile.c"
#include "io/sink_apple_audio.h"
#include "io/sink_wavwrite.c"
#include "io/source.h"
#include "io/source_avcodec.c"
#include "io/source_sndfile.h"
#include "io/sink_flac.c"
#include "io/source_apple_audio.c"
#include "io/utils_apple_audio.c"
#include "io/audio_unit.c"
#include "io/sink.h"
#include "io/ioutils.c"
#include "io/sink_sndfile.h"
#include "io/source_wavread.c"
#include "io/source.c"
#include "io/sink_wavwrite.h"
#include "io/sink_apple_audio.c"
#include "io/source_apple_audio.h"
#include "io/source_avcodec.h"
#include "io/source_sndfile.c"
#include "utils/log.c"
#include "utils/scale.h"
#include "utils/hist.h"
#include "utils/parameter.h"
#include "utils/windll.c"
#include "utils/hist.c"
#include "utils/scale.c"
#include "utils/log.h"
#include "utils/parameter.c"
#include "utils/strutils.c"
#include "mathutils.c"
#include "lvec.c"
#include "spectral/filterbank_mel.c"
#include "spectral/fft.h"
#include "spectral/dct_ooura.c"
#include "spectral/filterbank.h"
#include "spectral/mfcc.h"
#include "spectral/statistics.c"
#include "spectral/dct.h"
#include "spectral/tss.c"
#include "spectral/dct_fftw.c"
#include "spectral/specdesc.c"
#include "spectral/phasevoc.h"
#include "spectral/awhitening.c"
#include "spectral/filterbank.c"
#include "spectral/filterbank_mel.h"
#include "spectral/dct_accelerate.c"
#include "spectral/fft.c"
#include "spectral/dct.c"
#include "spectral/mfcc.c"
#include "spectral/tss.h"
#include "spectral/phasevoc.c"
#include "spectral/dct_plain.c"
#include "spectral/awhitening.h"
#include "spectral/dct_ipp.c"
#include "spectral/specdesc.h"
#include "spectral/ooura_fft8g.c"
#include "aubio_priv.h"
#include "aubio_ffi.h"
#include "cvec.c"
#include "synth/wavetable.h"
#include "synth/sampler.h"
#include "synth/sampler.c"
#include "synth/wavetable.c"
#include "notes/notes.c"
#include "notes/notes.h"
#include "musicutils.h"
#include "tempo/tempo.c"
#include "tempo/beattracking.c"
#include "tempo/beattracking.h"
#include "tempo/tempo.h"
#include "fvec.h"
#include "fmat.h"
#include "vecutils.h"
#include "effects/pitchshift_dummy.c"
#include "effects/timestretch_rubberband.c"
#include "effects/timestretch_dummy.c"
#include "effects/rubberband_utils.c"
#include "effects/timestretch.h"
#include "effects/pitchshift_rubberband.c"
#include "effects/pitchshift.h"
#include "lvec.h"
#include "onset/peakpicker.c"
#include "onset/onset.c"
#include "onset/onset.h"
#include "onset/peakpicker.h"
#include "mathutils.h"
