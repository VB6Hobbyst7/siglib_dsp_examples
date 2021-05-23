/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package siglib_wrap;

public final class SLClipMode_t {
  public final static SLClipMode_t SIGLIB_CLIP_ABOVE = new SLClipMode_t("SIGLIB_CLIP_ABOVE", siglib_wrapJNI.SIGLIB_CLIP_ABOVE_get());
  public final static SLClipMode_t SIGLIB_CLIP_BOTH = new SLClipMode_t("SIGLIB_CLIP_BOTH", siglib_wrapJNI.SIGLIB_CLIP_BOTH_get());
  public final static SLClipMode_t SIGLIB_CLIP_BELOW = new SLClipMode_t("SIGLIB_CLIP_BELOW", siglib_wrapJNI.SIGLIB_CLIP_BELOW_get());

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static SLClipMode_t swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + SLClipMode_t.class + " with value " + swigValue);
  }

  private SLClipMode_t(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private SLClipMode_t(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private SLClipMode_t(String swigName, SLClipMode_t swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static SLClipMode_t[] swigValues = { SIGLIB_CLIP_ABOVE, SIGLIB_CLIP_BOTH, SIGLIB_CLIP_BELOW };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

