#ifndef SHADERS_HPP
#define SHADERS_HPP
    const char* vertexShader = "attribute vec2 coord2d;\n"
                               "attribute vec3 color;\n"
                               "varying vec3 vColor;\n"
                               "void main(void)\n"
                               "{\n"
                               "    gl_Position = vec4(coord2d.x, coord2d.y, 0.0, 1.0);\n"
                               "    vColor = color;\n"
                               "}\n";

const char* fragmentShader =   "varying vec3 vColor;\n"
                               "void main(void)\n"
                               "{\n"
                               "   gl_FragColor[0] = vColor.r;\n"
                               "   gl_FragColor[1] = vColor.g;\n"
                               "   gl_FragColor[2] = vColor.b;\n"
                               "}\n";


#endif // SHADERS_HPP
