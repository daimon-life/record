```c++

// buffer
GLuint vboid
glGenBuffers(1,&vboid);
glBindBuffer(GL_ARRAY_BUFFER,vboid);

// vertex array
unsigned int VBO, VAO;
glGenVertexArrays(1, &vaoid);
glBindVertexArray(vaoid);

// copy to ...
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 

// vertex shader
unsigned int vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//传递源码
glCompileShader(vertexShader);//编译着色器
glDeleteShader(vertexShader);

// fragment shader
unsigned int fragmentShader;
fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(fragmentShader);
glDeleteShader(fragmentShader);

// shader program
unsigned int shaderProgram;
shaderProgram = glCreateProgram();//创建一个着色器程序对象
glAttachShader(shaderProgram, vertexShader);//将顶点着色器附加到程序上
glAttachShader(shaderProgram, fragmentShader);//将片段着色器附加到程序上
glLinkProgram(shaderProgram);//链接
glUseProgram(shaderProgram);


//
glDrawArrays(GL_TRIANGLES, 0, 3);

```
