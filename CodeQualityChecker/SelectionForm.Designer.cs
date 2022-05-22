
namespace CodeQualityChecker
{
    partial class SelectionForm
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
            this.Test = new System.Windows.Forms.CheckedListBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.UnselectButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.RunDoxygen = new System.Windows.Forms.Button();
            this.FindDoxygen = new System.Windows.Forms.Button();
            this.RunButton = new System.Windows.Forms.Button();
            this.doxyFileDisplay = new System.Windows.Forms.TextBox();
            this.FileDisplay = new System.Windows.Forms.RichTextBox();
            this.FileSelect = new System.Windows.Forms.Button();
            this.testName = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Test
            // 
            this.Test.BackColor = System.Drawing.SystemColors.Window;
            this.Test.CheckOnClick = true;
            this.Test.FormattingEnabled = true;
            this.Test.Items.AddRange(new object[] {
            "Assess Spacing",
            "Empty Line Count",
            "Semicolon Placement",
            "Equality Operators use",
            "Class Counting and CamelCase Check"});
            this.Test.Location = new System.Drawing.Point(16, 62);
            this.Test.MinimumSize = new System.Drawing.Size(200, 140);
            this.Test.Name = "Test";
            this.Test.Size = new System.Drawing.Size(200, 140);
            this.Test.TabIndex = 0;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.testName);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.UnselectButton);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.RunDoxygen);
            this.panel1.Controls.Add(this.FindDoxygen);
            this.panel1.Controls.Add(this.RunButton);
            this.panel1.Controls.Add(this.doxyFileDisplay);
            this.panel1.Controls.Add(this.FileDisplay);
            this.panel1.Controls.Add(this.FileSelect);
            this.panel1.Controls.Add(this.Test);
            this.panel1.Location = new System.Drawing.Point(13, 13);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(775, 350);
            this.panel1.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 42);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(89, 17);
            this.label2.TabIndex = 9;
            this.label2.Text = "Tests to Run";
            // 
            // UnselectButton
            // 
            this.UnselectButton.Location = new System.Drawing.Point(569, 62);
            this.UnselectButton.Name = "UnselectButton";
            this.UnselectButton.Size = new System.Drawing.Size(127, 37);
            this.UnselectButton.TabIndex = 8;
            this.UnselectButton.Text = "Unselect All Files";
            this.UnselectButton.UseVisualStyleBackColor = true;
            this.UnselectButton.Click += new System.EventHandler(this.UnselectButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(433, 105);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(96, 17);
            this.label1.TabIndex = 7;
            this.label1.Text = "Files Selected";
            // 
            // RunDoxygen
            // 
            this.RunDoxygen.Location = new System.Drawing.Point(250, 128);
            this.RunDoxygen.Name = "RunDoxygen";
            this.RunDoxygen.Size = new System.Drawing.Size(120, 32);
            this.RunDoxygen.TabIndex = 6;
            this.RunDoxygen.Text = "Run Doxygen";
            this.RunDoxygen.UseVisualStyleBackColor = true;
            this.RunDoxygen.Click += new System.EventHandler(this.RunDoxygen_Click);
            // 
            // FindDoxygen
            // 
            this.FindDoxygen.Location = new System.Drawing.Point(250, 62);
            this.FindDoxygen.Name = "FindDoxygen";
            this.FindDoxygen.Size = new System.Drawing.Size(120, 32);
            this.FindDoxygen.TabIndex = 5;
            this.FindDoxygen.Text = "Find Doxygen";
            this.FindDoxygen.UseVisualStyleBackColor = true;
            this.FindDoxygen.Click += new System.EventHandler(this.FindDoxygen_Click);
            // 
            // RunButton
            // 
            this.RunButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RunButton.Location = new System.Drawing.Point(250, 217);
            this.RunButton.Name = "RunButton";
            this.RunButton.Size = new System.Drawing.Size(119, 48);
            this.RunButton.TabIndex = 4;
            this.RunButton.Text = "Run Tests";
            this.RunButton.UseVisualStyleBackColor = true;
            this.RunButton.Click += new System.EventHandler(this.RunButton_Click);
            // 
            // doxyFileDisplay
            // 
            this.doxyFileDisplay.Location = new System.Drawing.Point(250, 100);
            this.doxyFileDisplay.Multiline = true;
            this.doxyFileDisplay.Name = "doxyFileDisplay";
            this.doxyFileDisplay.ReadOnly = true;
            this.doxyFileDisplay.Size = new System.Drawing.Size(149, 22);
            this.doxyFileDisplay.TabIndex = 3;
            this.doxyFileDisplay.Text = "No file selected";
            // 
            // FileDisplay
            // 
            this.FileDisplay.Location = new System.Drawing.Point(436, 133);
            this.FileDisplay.Name = "FileDisplay";
            this.FileDisplay.ReadOnly = true;
            this.FileDisplay.Size = new System.Drawing.Size(260, 159);
            this.FileDisplay.TabIndex = 2;
            this.FileDisplay.Text = "No files selected";
            this.FileDisplay.TextChanged += new System.EventHandler(this.FileDisplay_TextChanged);
            // 
            // FileSelect
            // 
            this.FileSelect.Location = new System.Drawing.Point(436, 62);
            this.FileSelect.Name = "FileSelect";
            this.FileSelect.Size = new System.Drawing.Size(127, 37);
            this.FileSelect.TabIndex = 1;
            this.FileSelect.Text = "Select Files";
            this.FileSelect.UseVisualStyleBackColor = true;
            this.FileSelect.Click += new System.EventHandler(this.FileSelect_Click);
            // 
            // testName
            // 
            this.testName.Location = new System.Drawing.Point(481, 34);
            this.testName.MaxLength = 50;
            this.testName.Multiline = true;
            this.testName.Name = "testName";
            this.testName.Size = new System.Drawing.Size(193, 22);
            this.testName.TabIndex = 10;
            this.testName.Text = "Test Name (optional)";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(24, 205);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(166, 17);
            this.label3.TabIndex = 11;
            this.label3.Text = "(Currently Nonfunctional)";
            // 
            // SelectionForm
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(800, 381);
            this.Controls.Add(this.panel1);
            this.MinimumSize = new System.Drawing.Size(818, 428);
            this.Name = "SelectionForm";
            this.Text = "Automated Code Quality Checker";
            this.Load += new System.EventHandler(this.SelectionForm_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckedListBox Test;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button FileSelect;
        private System.Windows.Forms.TextBox doxyFileDisplay;
        private System.Windows.Forms.RichTextBox FileDisplay;
        private System.Windows.Forms.Button RunButton;
        private System.Windows.Forms.Button FindDoxygen;
        private System.Windows.Forms.Button RunDoxygen;
        private System.Windows.Forms.Button UnselectButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox testName;
    }
}

