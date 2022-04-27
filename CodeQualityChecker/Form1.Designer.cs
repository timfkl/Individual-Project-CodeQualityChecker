
namespace CodeQualityChecker
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Box = new System.Windows.Forms.CheckedListBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.FindDoxygen = new System.Windows.Forms.Button();
            this.RunButton = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.FileDisplay = new System.Windows.Forms.RichTextBox();
            this.FileSelect = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Box
            // 
            this.Box.BackColor = System.Drawing.SystemColors.Window;
            this.Box.FormattingEnabled = true;
            this.Box.Location = new System.Drawing.Point(3, 45);
            this.Box.Name = "Box";
            this.Box.Size = new System.Drawing.Size(200, 242);
            this.Box.TabIndex = 0;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.FindDoxygen);
            this.panel1.Controls.Add(this.RunButton);
            this.panel1.Controls.Add(this.textBox1);
            this.panel1.Controls.Add(this.FileDisplay);
            this.panel1.Controls.Add(this.FileSelect);
            this.panel1.Controls.Add(this.Box);
            this.panel1.Location = new System.Drawing.Point(13, 13);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(775, 425);
            this.panel1.TabIndex = 1;
            // 
            // FindDoxygen
            // 
            this.FindDoxygen.Location = new System.Drawing.Point(315, 112);
            this.FindDoxygen.Name = "FindDoxygen";
            this.FindDoxygen.Size = new System.Drawing.Size(120, 32);
            this.FindDoxygen.TabIndex = 5;
            this.FindDoxygen.Text = "Find Doxygen";
            this.FindDoxygen.UseVisualStyleBackColor = true;
            this.FindDoxygen.Click += new System.EventHandler(this.FindDoxygen_Click);
            // 
            // RunButton
            // 
            this.RunButton.Location = new System.Drawing.Point(252, 328);
            this.RunButton.Name = "RunButton";
            this.RunButton.Size = new System.Drawing.Size(119, 23);
            this.RunButton.TabIndex = 4;
            this.RunButton.Text = "Run Tests";
            this.RunButton.UseVisualStyleBackColor = true;
            this.RunButton.Click += new System.EventHandler(this.RunButton_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(462, 159);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(165, 22);
            this.textBox1.TabIndex = 3;
            // 
            // FileDisplay
            // 
            this.FileDisplay.Location = new System.Drawing.Point(442, 206);
            this.FileDisplay.Name = "FileDisplay";
            this.FileDisplay.ReadOnly = true;
            this.FileDisplay.Size = new System.Drawing.Size(274, 159);
            this.FileDisplay.TabIndex = 2;
            this.FileDisplay.Text = "";
            this.FileDisplay.TextChanged += new System.EventHandler(this.FileDisplay_TextChanged);
            // 
            // FileSelect
            // 
            this.FileSelect.Location = new System.Drawing.Point(500, 62);
            this.FileSelect.Name = "FileSelect";
            this.FileSelect.Size = new System.Drawing.Size(127, 37);
            this.FileSelect.TabIndex = 1;
            this.FileSelect.Text = "Select Files";
            this.FileSelect.UseVisualStyleBackColor = true;
            this.FileSelect.Click += new System.EventHandler(this.FileSelect_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Code Quality Checker";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckedListBox Box;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button FileSelect;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.RichTextBox FileDisplay;
        private System.Windows.Forms.Button RunButton;
        private System.Windows.Forms.Button FindDoxygen;
    }
}

