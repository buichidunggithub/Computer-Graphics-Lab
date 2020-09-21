using SharpGL;
using System.Drawing;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    class Camera
    {
        public double eyeX, eyeY, eyeZ;
        public double centerX, centerY, centerZ;
        public double radius;
        public double theta;
        public double fi;

        public Camera()
        {
            eyeX = 10;
            eyeY = 5;
            eyeZ = 10;
            centerX = 0;
            centerY = 0;
            centerZ = 0;

            Caculate_Radius();
            Caculate_Theta();
            Caculate_Fi();
        }

        // Tính góc theta hiện tại
        public void Caculate_Theta()
        {
            // Trường hợp điểm nhìn không phải gốc tọa độ thì trừ centerX
            theta = Math.Atan((eyeX - centerX) / (eyeZ - centerZ));
        }

        // Tính góc fi hiện tại
        public void Caculate_Fi()
        {
            // // Trường hợp điểm nhìn không phải gốc tọa độ thì trừ centerY
            fi = Math.Asin((eyeY - centerY) / radius);
        }

        // Tính bán kính của hình cầu khi thay đổi vị trí camera (khoảng cách từ cam đến look)
        public void Caculate_Radius()
        {
            radius = Math.Sqrt(Math.Pow(eyeX - centerX, 2)
                     + Math.Pow(eyeY - centerY, 2)
                     + Math.Pow(eyeZ - centerZ, 2));
        }

        // Phóng to - di chuyển vị trí camera lại gần điểm nhìn
        public void ZoomIn()
        {
            eyeX += -0.017f * eyeX;
            eyeY += -0.017f * eyeY;
            eyeZ += -0.017f * eyeZ;

            // Khi di chuyển vị trí camera thì bán kính hình cầu sẽ thay đổi nên cần cập nhật lại
            Caculate_Radius();
            Caculate_Theta();
            Caculate_Fi();
        }

        // Thu nhỏ - di chuyển vị trí camera ra xa điểm nhìn
        public void ZoomOut()
        {
            eyeX += 0.017f * eyeX;
            eyeY += 0.017f * eyeY;
            eyeZ += 0.017f * eyeZ;

            // Khi di chuyển vị trí camera thì bán kính hình cầu sẽ thay đổi nên cần cập nhật lại
            Caculate_Radius();
            Caculate_Theta();
            Caculate_Fi();
        }

        // Di chuyển camera quay xung quanh điểm nhìn sang phải
        public void RotateRight()
        {
            theta += 0.017;
            eyeX = centerX + radius * Math.Cos(fi) * Math.Sin(theta);
            eyeZ = centerZ + radius * Math.Cos(fi) * Math.Cos(theta);
        }

        // Di chuyển camera quay xung quanh điểm nhìn sang trái 
        public void RotateLeft()
        {
            theta -= 0.017;
            eyeX = centerX + radius * Math.Cos(fi) * Math.Sin(theta);
            eyeZ = centerZ + radius * Math.Cos(fi) * Math.Cos(theta);
        }

        // Di chuyển camera quay xung quanh điểm nhìn lên trên
        public void RotateUp()
        {
            fi += 0.017;
            eyeY = centerY + radius * Math.Sin(fi);
            eyeZ = centerZ + radius * Math.Cos(fi) * Math.Cos(theta);
            eyeX = centerX + radius * Math.Cos(fi) * Math.Sin(theta);
        }

        // Di chuyển camera quay xung quanh điểm nhìn xuống dưới
        public void RotateDown()
        {
            fi -= 0.017;

            eyeY = centerY + radius * Math.Sin(fi);
            eyeZ = centerZ + radius * Math.Cos(fi) * Math.Cos(theta);
            eyeX = centerX + radius * Math.Cos(fi) * Math.Sin(theta);
        }
    }
}
