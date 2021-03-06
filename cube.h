#ifndef CUBE_H
#define CUBE_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

#include <QElapsedTimer>
#include <QMatrix4x4>

#include "camera.h"

class Cube : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Cube();
    ~Cube();

public slots:
    void updateGLScene();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    // ATTRIBUTES >>
    QOpenGLContext              *m_pContext;
    QOpenGLVertexArrayObject    m_CubeVAO;
    QOpenGLBuffer               *m_pCubeVB;
    QOpenGLBuffer               *m_pCubeIB;
    QOpenGLShader               *m_pColorVS;
    QOpenGLShader               *m_pColorFS;
    QOpenGLShaderProgram        *m_pColorSP;

    QElapsedTimer   m_Timer;
    Camera          m_Camera;

    QMatrix4x4      m_mtxRotation;
    QMatrix4x4      m_mtxViewProj;
    QMatrix4x4      m_mtxWorldViewProj;
    // << ATTRIBUTES

    void buildBuffers();
    bool manageShaders();
};

#endif // CUBE_H
