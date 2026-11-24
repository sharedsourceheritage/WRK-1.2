namespace DefaultNamespace 
{
    using System;
    using System.Drawing;
    using System.Collections;
    using System.ComponentModel;
    using System.Windows.Forms;

	public class FigureDrawingObject : Form

	{
		void Draw(PaintEventArgs e)
		{
			//Subclasses should implement
		}
		
		void SetPenColor(int color)
		{
			Pen coloredPen = new Pen(Color.Black);
			if (color == 0)
				coloredPen = new Pen(Color.Red);
			if (color == 1)
				coloredPen = new Pen(Color.White);
			if (color == 2)
				coloredPen = new Pen(Color.Blue);
			if (color == 3)
				coloredPen = new Pen(Color.Black);
			if (color == 4)
				coloredPen = new Pen(Color.Yellow);
		}

		Color GetColor(int color)
		{
			if (color == 0)
				return Color.Red;
			if (color == 1)
				return Color.White;
			if (color == 2)
				return Color.Blue;
			if (color == 3)
				return Color.Black;
			if (color == 4)
				return Color.Yellow;
			
			return Color.Black;
		}
			
		public void DrawRectangle(PaintEventArgs e, int offsetX, int offsetY, int color, int topLeftX, int topLeftY, int width, int height)
		{
			Pen coloredPen = new Pen(GetColor(color));
			e.Graphics.DrawRectangle(coloredPen, offsetX + topLeftX, offsetY + topLeftY, width, height);
		}
		
		public void DrawCircle(PaintEventArgs e, int offsetX, int offsetY, int color, int topLeftX, int topLeftY, int radius)
		{
			Pen coloredPen = new Pen(this.GetColor(color));
			e.Graphics.DrawEllipse(coloredPen, offsetX + topLeftX-radius, offsetY + topLeftY-radius, radius*2, radius*2);
		}

		public void DrawLineAndArrow(PaintEventArgs e, int nodeOffsetX, int nodeOffsetY, int color, int startX, int startY, int endX, int endY)
		{
			//The node offset values are provided from a set of
			//drawing instructions from outside the fig language
			Pen coloredPen = new Pen(this.GetColor(color));
			Point from = new Point(nodeOffsetX + startX, nodeOffsetY + startY);
			Point to = new Point(nodeOffsetX + endX, nodeOffsetY + endY);
			e.Graphics.DrawLine(coloredPen, from, to); 
			this.DrawArrow(e, coloredPen, color, startX + nodeOffsetX , startY + nodeOffsetY, endX + nodeOffsetX, endY + nodeOffsetY);
		}
		
		void DrawArrow(PaintEventArgs e, Pen coloredPen, int color, int fromX, int fromY, int toX, int toY)
		{
			Point from = new Point(fromX, fromY);
			Point to = new Point(toX, toY);
			double PI = 3.14159;
			int deltaY = to.Y - from.Y; 
			int deltaX = to.X - from.X; 
			
			double hypotenus = Math.Sqrt(deltaY*deltaY+deltaX*deltaX);
			double angle;
			if (deltaX > 0)
				angle = Math.Asin(deltaY/hypotenus);
			else
				angle = Math.Acos(deltaX/hypotenus);
			if (deltaX < 0 && deltaY <0) 
				angle = 2*PI - angle;
			
			double arrowAngle = 5*PI/36; //The arrow is 25 degrees either side of the line
			int radius = 15;
			
			double angleOne = 0;
			double angleTwo = 0;
			
			angleOne = angle - arrowAngle;
			angleTwo = angle + arrowAngle;
				
			double arrowOneXDouble = (Math.Cos(angleOne))* radius;
			double arrowOneYDouble = (Math.Sin(angleOne))* radius;
			int arrowOneX = (int) arrowOneXDouble;
			int arrowOneY = (int) arrowOneYDouble;
			
			//Mirror the coordinates
			arrowOneX = arrowOneX * -1;
			arrowOneY = arrowOneY * -1;
			
			Point arrowOne = new Point(to.X + arrowOneX, to.Y + arrowOneY); 
			e.Graphics.DrawLine(coloredPen, to, arrowOne);
			
			double arrowTwoXDouble = (Math.Cos(angleTwo))* radius;
			double arrowTwoYDouble = (Math.Sin(angleTwo))* radius;
			int arrowTwoX = (int) arrowTwoXDouble;
			int arrowTwoY = (int) arrowTwoYDouble;
			
			//Mirror the coordinates
			arrowTwoX = arrowTwoX * -1;
			arrowTwoY = arrowTwoY * -1;
			
			Point arrowTwo = new Point(to.X + arrowTwoX, to.Y + arrowTwoY); 
			e.Graphics.DrawLine(coloredPen, to, arrowTwo);
		}
	}
}