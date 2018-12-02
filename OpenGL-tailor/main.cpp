
//
//  main.cpp
//  OpenGL-tailor
//
//  Created by lxj on 2018/12/2.
//  Copyright © 2018 lxj. All rights reserved.
//

#include <stdio.h>

#include "GLTools.h"
#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif


void renderScreen(void){
    //设置清屏颜色为蓝色
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glEnable(GL_SCISSOR_TEST);
    //1.现在剪成小红色分区
    //(1)设置裁剪区颜色为红色
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    //(2)设置裁剪尺寸
    glScissor(100, 100, 600, 400);
    //(3)开启裁剪测试
    
    //(4)开启清屏，执行裁剪
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    // 2.裁剪一个绿色的小矩形
    //(1).设置清屏颜色为绿色
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    //(2).设置裁剪尺寸
    glScissor(200, 200, 400, 200);
    //(3).开始清屏执行裁剪
    glClear(GL_COLOR_BUFFER_BIT);
    
    //关闭裁剪测试
    glDisable(GL_SCISSOR_TEST);
    
    //强制执行缓存区
    glutSwapBuffers();
}

void changeSize(int w, int h){
    glViewport(0, 0, w, h);
}


int main(int argc, char*argv[]){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("裁剪");
    
    
    glutDisplayFunc(renderScreen);
    glutReshapeFunc(changeSize);
    
    glutMainLoop();
    
    return 0;
}
