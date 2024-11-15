class Animation {
public:
    Animation(int startFrame, int endFrame, float frameTime) 
        : startFrame(startFrame), endFrame(endFrame), frameTime(frameTime) {}

    Animation() : startFrame(0), endFrame(0), frameTime(0.0f) {}

    int startFrame;
    int endFrame;
    float frameTime;
};