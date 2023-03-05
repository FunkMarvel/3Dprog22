#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <QWindow>
#include <QTimer>
#include <QElapsedTimer>

#include "camera.h"

class QOpenGLContext;
class Shader;
class MainWindow;

/// This inherits from QWindow to get access to the Qt functionality and
// OpenGL surface.
// We also inherit from QOpenGLFunctions, to get access to the OpenGL functions
// This is the same as using "glad" and "glw" from general OpenGL tutorials
class RenderWindow : public QWindow, protected QOpenGLFunctions_4_1_Core {
    Q_OBJECT

public:
    RenderWindow(const QSurfaceFormat& format, MainWindow* mainWindow);
    ~RenderWindow() override;

    QOpenGLContext* context() {
        return mContext;
    }

    void exposeEvent(QExposeEvent*) override; //gets called when app is shown and resized

    bool mRotate{true}; //Check if triangle should rotate
    bool XYZ_render{false};
    bool Curve_render{false};
    bool Plane_render{false};
    bool Cube_render{false};
    bool drawNormals{false};

    template <typename T> int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }

private
slots:
    void render(); //the actual render - function

private:
    float dt{-10000};
    float _gravity{-9.81f};
    QVector3D _movVec{};
    //Vertex m_v;

    std::map<int, bool> pressedKeys{};

    std::unordered_map<std::string, class VisualObject*> mObjects;
    class Pawn* _pawn;

    Camera mCamera{};

    void init(); //initialize things we need before rendering

    class QOpenGLContext* mContext{nullptr}; //Our OpenGL context
    bool mInitialized{false};

    class Shader* mShaderProgram{nullptr}; //holds pointer the GLSL shader program

    GLint mPmatrixUniform{}; //OPenGL reference to the uniform in the shader program
    GLint mVmatrixUniform{};
    GLint mMmatrixUniform{};

    GLuint mVAO{}; //OpenGL reference to our VAO
    GLuint mVBO{}; //OpenGL reference to our VBO


    class QTimer* mRenderTimer{nullptr}; //timer that drives the gameloop
    QElapsedTimer mTimeStart;            //time variable that reads the calculated FPS

    class MainWindow* mMainWindow{nullptr}; //points back to MainWindow to be able to put info in StatusBar

    class QOpenGLDebugLogger* mOpenGLDebugLogger{nullptr}; //helper class to get some clean debug info from OpenGL
    class Logger* mLogger{nullptr};                        //logger - Output Log in the application

    ///Helper function that uses QOpenGLDebugLogger or plain glGetError()
    void checkForGLerrors();

    void calculateFramerate(); //as name says

    ///Starts QOpenGLDebugLogger if possible
    void startOpenGLDebugger();

    QVector3D cameraLastPos;

protected:
    //The QWindow that we inherit from have these functions to capture
    // - mouse and keyboard.
    // Uncomment to use (you also have to make the definitions of
    // these functions in the cpp-file to use them of course!)
    //
    //    void mousePressEvent(QMouseEvent *event) override{}
    //    void mouseMoveEvent(QMouseEvent *event) override{}
    void keyPressEvent(QKeyEvent* event) override; //the only one we use now
    void keyReleaseEvent(QKeyEvent* event) override;
    //    void wheelEvent(QWheelEvent *event) override{}

    void MoveByInput(class VisualObject*);
    void RotateByInput(class VisualObject*);
    void InitMoveKeys();
    void ChangeCamera();

};

#endif // RENDERWINDOW_H
