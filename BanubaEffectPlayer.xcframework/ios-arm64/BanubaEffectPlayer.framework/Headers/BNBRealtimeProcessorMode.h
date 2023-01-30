// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BNBRealtimeProcessorMode)
{
    /** Synchronous mode. Frame drop not allowed, `pop` will block on processing. */
    BNBRealtimeProcessorModeSync,
    /**
     * Synchronous mode when effect loaded. Frame drop not allowed.
     * During effect loading `push` will forward frames to `pop`, `pop` will return SKIP.
     * When effect loaded, `pop` will block on processing.
     */
    BNBRealtimeProcessorModeSyncWhenEffectLoaded,
    /**
     * Asynchronous mode. Frame drop is allowed. `push` and `pop` do not block on processing.
     * `push` can drop frames, if processor busy,
     * `pop` can return EMPTY, if no processed frame data for now.
     */
    BNBRealtimeProcessorModeAsync,
    /**
     * Asynchronous mode. Frame drop is allowed. `push` and `pop` do not block on processing.
     * During effect loading `push` will forward frames to `pop`, `pop` will return SKIP.
     * When effect loaded, `push` can drop frames, if processor busy,
     * `pop` can return EMPTY, if no processed frame data for now.
     */
    BNBRealtimeProcessorModeAsyncWhenEffectLoaded,
};
