using SharpGL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    class Drawing
    {
        public static List<Object> listObject = new List<Object>();
        public static Object chooseObject(OpenGLControl openGLControl, int _chooseIcon, Vertex center)
        {
            Object choose_Object = null;

            //Xử lý chọn Object để vẽ.
            switch (_chooseIcon)
            {
                case 1://Cube
                    choose_Object = new Cube();
                    break;
                case 2://Pyramid - Hình chóp đáy là hình vuông
                    choose_Object = new Pyramid();
                    break;
                case 3://Prism - Hình lăng trụ đáy là tam giác đều 
                    choose_Object = new Prism();
                    break;
                default:
                    break;
            }
            if (choose_Object != null) // nếu tạo được object
            {
                choose_Object.name += Object._countObjects.ToString();
                listObject.Add(choose_Object);
            }
            return choose_Object;
        }

        //Vẽ đối tượng ra từ stack
        public static void Draw_Object(OpenGLControl openGLControl)
        {
            var gl = openGLControl.OpenGL;
            foreach (var x in listObject)
            {
                gl.PushMatrix();
                x.Draw(openGLControl);
                gl.PopMatrix();
            }
        }
    }
}
