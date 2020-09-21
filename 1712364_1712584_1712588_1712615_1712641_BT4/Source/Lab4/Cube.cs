using SharpGL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Threading.Tasks;
using SharpGL.SceneGraph.Assets;

namespace Lab4
{
    class Cube : Object
    {
        private Vertex delta;//dịch tâm một tọa độ delta(x,y,z)
        public Cube() //màu nền, tâm, chiều dài cạnh, check đang chọn
        {
            color = Color.White; //màu nền mặt phẳng ban đầu
            len = 3.0f;

            delta = new Vertex(pX - 0 - len / 2, pY - 0 - len / 2, pZ - 0 - len / 2);
            check = false; //check xem có đang thao tác trên hình này không
            type = 0;
            isTexture = false;
            texture = new Texture();

            listVertex = new List<Vertex> { new Vertex(), new Vertex(), new Vertex(), new Vertex(), new Vertex(), new Vertex(), new Vertex(), new Vertex() };
            rX = rY = rZ = 0;
            pX = pY = pZ = 0;
            sX = sY = sZ = 1;

        }
        private void Save()
        {
            delta.x = pX - 0 - len / 2;
            delta.y = pY - 0 - len / 2;
            delta.z = pZ - 0 - len / 2;

            //V1 = new Vertex(0 + delta.x, 0 + delta.y, 0 + delta.z);
            listVertex[0].x = 0 + delta.x;
            listVertex[0].y = 0 + delta.y;
            listVertex[0].z = 0 + delta.z;
            //V2 = new Vertex(0 + delta.x, len + delta.y, 0 + delta.z);
            listVertex[1].x = 0 + delta.x;
            listVertex[1].y = len + delta.y;
            listVertex[1].z = 0 + delta.z;
            //V3 = new Vertex(len + delta.x, len + delta.y, 0 + delta.z);
            listVertex[2].x = len + delta.x;
            listVertex[2].y = len + delta.y;
            listVertex[2].z = 0 + delta.z;
            //V4 = new Vertex(len + delta.x, 0 + delta.y, 0 + delta.z);
            listVertex[3].x = len + delta.x;
            listVertex[3].y = 0 + delta.y;
            listVertex[3].z = 0 + delta.z;
            //V5 = new Vertex(0 + delta.x, len + delta.y, len + delta.z);
            listVertex[4].x = 0 + delta.x;
            listVertex[4].y = len + delta.y;
            listVertex[4].z = len + delta.z;
            //V6 = new Vertex(0 + delta.x, 0 + delta.y, len + delta.z);
            listVertex[5].x = 0 + delta.x;
            listVertex[5].y = 0 + delta.y;
            listVertex[5].z = len + delta.z;
            //V7 = new Vertex(len + delta.x, 0 + delta.y, len + delta.z);
            listVertex[6].x = len + delta.x;
            listVertex[6].y = 0 + delta.y;
            listVertex[6].z = len + delta.z;
            //V8 = new Vertex(len + delta.x, len + delta.y, len + delta.z);
            listVertex[7].x = len + delta.x;
            listVertex[7].y = len + delta.y;
            listVertex[7].z = len + delta.z;
        }
        public override void Draw(OpenGLControl glControl)
        {
            OpenGL gl = glControl.OpenGL;
            Save();
            gl.PushMatrix();
            gl.Rotate((float)rX, (float)rY, (float)rZ);
            gl.Translate(pX, pY, pZ);
            gl.Scale(sX, sY, sZ);

            gl.Color(color.R / 255.0, color.G / 255.0, color.B / 255.0, 0);
            //Vẽ khối hoặc vẽ và dán texture
            if (isTexture)
                Paste_Texture(gl);
            else
                DrawRaw(gl);
            //Viền khung
            Borders(gl);
            gl.PopMatrix();
            gl.Flush();
        }
        private void DrawRaw(OpenGL gl)
        {
            gl.Begin(OpenGL.GL_QUADS);
            //Vẽ mặt phẳng

            //Bottom
            gl.Vertex(0 + delta.x, 0 + delta.y, 0 + delta.z);//V1 : Top right of the Quad
            gl.Vertex(0 + delta.x, len + delta.y, 0 + delta.z);//V2 : Top left of the Quad
            gl.Vertex(len + delta.x, len + delta.y, 0 + delta.z); //V3 : Bottom left of the quad
            gl.Vertex(len + delta.x, 0 + delta.y, 0 + delta.z); //V4 : Bottom right of the Quad

            //Front
            gl.Vertex(0 + delta.x, 0 + delta.y, 0 + delta.z); //V1 : Top right of the Quad
            gl.Vertex(0 + delta.x, len + delta.y, 0 + delta.z); //V2 : Top left of the Quad
            gl.Vertex(0 + delta.x, len + delta.y, len + delta.z);//V5 : Bottom left of the Quad
            gl.Vertex(0 + delta.x, 0 + delta.y, len + delta.z);//V6 : Bottom right of the Quad

            //Top
            gl.Vertex(0 + delta.x, 0 + delta.y, 0 + delta.z); //V1 : Top right of the Quad
            gl.Vertex(0 + delta.x, 0 + delta.y, len + delta.z);//V6 : Bottom right of the Quad
            gl.Vertex(len + delta.x, 0 + delta.y, len + delta.z);//V7 : Bottom left of the Quad
            gl.Vertex(len + delta.x, 0 + delta.y, 0 + delta.z);//V4 : Top left of the Quad

            //Back
            gl.Vertex(0 + delta.x, 0 + delta.y, len + delta.z);//V6 : Bottom right of the Quad
            gl.Vertex(0 + delta.x, len + delta.y, len + delta.z);//V5 : Top right of the Quad
            gl.Vertex(len + delta.x, len + delta.y, len + delta.z);//V8 : Top left of the Quad
            gl.Vertex(len + delta.x, 0 + delta.y, len + delta.z);//V7 : Bottom left of the Quad

            //Right
            gl.Vertex(0 + delta.x, len + delta.y, 0 + delta.z);//V2 : Top right of the Quad
            gl.Vertex(0 + delta.x, len + delta.y, len + delta.z);//V5 : Bottom right of the Quad
            gl.Vertex(len + delta.x, len + delta.y, len + delta.z);//V8 : Bottom left of the Quad
            gl.Vertex(len + delta.x, len + delta.y, 0 + delta.z);//V3 : Top left of the Quad

            //Left
            gl.Vertex(len + delta.x, len + delta.y, 0 + delta.z);//V3 : Top left of the Quad
            gl.Vertex(len + delta.x, 0 + delta.y, 0 + delta.z);//V4 : Bottom left of the Quad
            gl.Vertex(len + delta.x, 0 + delta.y, len + delta.z);//V7 : Bottom right of the Quad
            gl.Vertex(len + delta.x, len + delta.y, len + delta.z);//V8 : Top right of the Quad

            gl.End();
        }

        private void Paste_Texture(OpenGL gl)
        {
            gl.Enable(OpenGL.GL_TEXTURE_2D);
            //Bind the texture.
            texture.Bind(gl);
            gl.Color(1f, 1f, 1f, 0);
            gl.Begin(OpenGL.GL_QUADS);
            //Vẽ mặt phẳng

            //Right face
            gl.TexCoord(1.0f, 1.0f); gl.Vertex(0 + delta.x, 0 + delta.y, 0 + delta.z);//V1
            gl.TexCoord(1.0f, 0.0f); gl.Vertex(0 + delta.x, len + delta.y, 0 + delta.z);//V2
            gl.TexCoord(0.0f, 0.0f); gl.Vertex(len + delta.x, len + delta.y, 0 + delta.z); //V3
            gl.TexCoord(0.0f, 1.0f); gl.Vertex(len + delta.x, 0 + delta.y, 0 + delta.z); //V4

            // Behind face
            gl.TexCoord(0.0f, 1.0f); gl.Vertex(0 + delta.x, 0 + delta.y, 0 + delta.z); //V1
            gl.TexCoord(0.0f, 0.0f); gl.Vertex(0 + delta.x, len + delta.y, 0 + delta.z); //V2
            gl.TexCoord(1.0f, 0.0f); gl.Vertex(0 + delta.x, len + delta.y, len + delta.z);//V5
            gl.TexCoord(1.0f, 1.0f); gl.Vertex(0 + delta.x, 0 + delta.y, len + delta.z);//V6

            //Down face
            gl.TexCoord(0.0f, 1.0f); gl.Vertex(0 + delta.x, 0 + delta.y, 0 + delta.z); //V1
            gl.TexCoord(0.0f, 0.0f); gl.Vertex(0 + delta.x, 0 + delta.y, len + delta.z);//V6
            gl.TexCoord(1.0f, 0.0f); gl.Vertex(len + delta.x, 0 + delta.y, len + delta.z);//V7
            gl.TexCoord(1.0f, 1.0f); gl.Vertex(len + delta.x, 0 + delta.y, 0 + delta.z);//V4

            //Left face
            gl.TexCoord(0.0f, 1.0f); gl.Vertex(0 + delta.x, 0 + delta.y, len + delta.z);//V6
            gl.TexCoord(0.0f, 0.0f); gl.Vertex(0 + delta.x, len + delta.y, len + delta.z);//V5
            gl.TexCoord(1.0f, 0.0f); gl.Vertex(len + delta.x, len + delta.y, len + delta.z);//V8
            gl.TexCoord(1.0f, 1.0f); gl.Vertex(len + delta.x, 0 + delta.y, len + delta.z);//V7

            // Up face
            gl.TexCoord(0.0f, 1.0f); gl.Vertex(0 + delta.x, len + delta.y, 0 + delta.z);//V2
            gl.TexCoord(0.0f, 0.0f); gl.Vertex(0 + delta.x, len + delta.y, len + delta.z);//V5
            gl.TexCoord(1.0f, 0.0f); gl.Vertex(len + delta.x, len + delta.y, len + delta.z);//V8
            gl.TexCoord(1.0f, 1.0f); gl.Vertex(len + delta.x, len + delta.y, 0 + delta.z);//V3

            //Front face
            gl.TexCoord(1.0f, 0.0f); gl.Vertex(len + delta.x, len + delta.y, 0 + delta.z);//V3
            gl.TexCoord(1.0f, 1.0f); gl.Vertex(len + delta.x, 0 + delta.y, 0 + delta.z);//V4
            gl.TexCoord(0.0f, 1.0f); gl.Vertex(len + delta.x, 0 + delta.y, len + delta.z);//V7
            gl.TexCoord(0.0f, 0.0f); gl.Vertex(len + delta.x, len + delta.y, len + delta.z);//V8

            gl.End();
            gl.Disable(OpenGL.GL_TEXTURE_2D);
        }


        private void Borders(OpenGL gl)
        {
            if (check) //nếu đang thao tác trên hình
            {
                //viền cam đậm
                gl.Color(236 / 255.0, 135 / 255.0, 14 / 255.0);
                //tăng kích cỡ viền
                gl.LineWidth((float)2);
            }
            else // nếu không thao tác
            {
                //viền đen nhạt
                gl.Color(255 / 255.0, 255 / 255.0, 255 / 255.0);
                //tăng kích cỡ viền
                gl.LineWidth((float)2);
            }

            gl.Begin(OpenGL.GL_LINES);
            //Vẽ các cạnh
            gl.Vertex(listVertex[0].x, listVertex[0].y, listVertex[0].z);
            gl.Vertex(listVertex[1].x, listVertex[1].y, listVertex[1].z);

            gl.Vertex(listVertex[1].x, listVertex[1].y, listVertex[1].z);
            gl.Vertex(listVertex[2].x, listVertex[2].y, listVertex[2].z);

            gl.Vertex(listVertex[2].x, listVertex[2].y, listVertex[2].z);
            gl.Vertex(listVertex[3].x, listVertex[3].y, listVertex[3].z);

            gl.Vertex(listVertex[0].x, listVertex[0].y, listVertex[0].z);
            gl.Vertex(listVertex[3].x, listVertex[3].y, listVertex[3].z);

            gl.Vertex(listVertex[1].x, listVertex[1].y, listVertex[1].z);
            gl.Vertex(listVertex[4].x, listVertex[4].y, listVertex[4].z);

            gl.Vertex(listVertex[5].x, listVertex[5].y, listVertex[5].z);
            gl.Vertex(listVertex[4].x, listVertex[4].y, listVertex[4].z);

            gl.Vertex(listVertex[5].x, listVertex[5].y, listVertex[5].z);
            gl.Vertex(listVertex[0].x, listVertex[0].y, listVertex[0].z);

            gl.Vertex(listVertex[5].x, listVertex[5].y, listVertex[5].z);
            gl.Vertex(listVertex[6].x, listVertex[6].y, listVertex[6].z);

            gl.Vertex(listVertex[3].x, listVertex[3].y, listVertex[3].z);
            gl.Vertex(listVertex[6].x, listVertex[6].y, listVertex[6].z);

            gl.Vertex(listVertex[4].x, listVertex[4].y, listVertex[4].z);
            gl.Vertex(listVertex[7].x, listVertex[7].y, listVertex[7].z);

            gl.Vertex(listVertex[6].x, listVertex[6].y, listVertex[6].z);
            gl.Vertex(listVertex[7].x, listVertex[7].y, listVertex[7].z);

            gl.Vertex(listVertex[2].x, listVertex[2].y, listVertex[2].z);
            gl.Vertex(listVertex[7].x, listVertex[7].y, listVertex[7].z);
            gl.End();

        }

        ~Cube()
        {
        }
    }
}
