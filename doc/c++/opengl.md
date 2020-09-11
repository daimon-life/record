```c++

// vertex buffer
GLuint vboid
glGenBuffers(1,&vboid);
glBindBuffer(GL_ARRAY_BUFFER,vboid);

// copy to ...
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 

// element buffer
GLuint eboid
glGenBuffers(1,&eboid);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboid);

// copy to ...
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexs), indexs, GL_STATIC_DRAW); 


// vertex array
unsigned int VBO, VAO;
glGenVertexArrays(1, &vaoid);
glBindVertexArray(vaoid);



// vertex shader
GLuint vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//传递源码
glCompileShader(vertexShader);//编译着色器
glDeleteShader(vertexShader);

// fragment shader
GLuint fragmentShader;
fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(fragmentShader);
glDeleteShader(fragmentShader);

// shader status
GLint compiled;
glGetShaderiv (shader, GL_COMPILE_STATUS, &compiled );
GLint infoLen = 0;
glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen );
char *infoLog = malloc(sizeof (char)*infoLen);
glGetShaderInfoLog (shader, infoLen, NULL, infoLog);

// shader program
unsigned int shaderProgram;
shaderProgram = glCreateProgram();//创建一个着色器程序对象
glAttachShader(shaderProgram, vertexShader);//将顶点着色器附加到程序上
glAttachShader(shaderProgram, fragmentShader);//将片段着色器附加到程序上
glLinkProgram(shaderProgram);//链接
glUseProgram(shaderProgram);
glDeleteProgram (shaderProgram);

// shader program status
GLint linked;
glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linked);
GLint infoLen = 0;
glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );
char *infoLog = malloc ( sizeof ( char ) * infoLen );
glGetProgramInfoLog (shaderProgram, infoLen, NULL, infoLog );

//
glDrawArrays(GL_TRIANGLES, 0, 3);

```
