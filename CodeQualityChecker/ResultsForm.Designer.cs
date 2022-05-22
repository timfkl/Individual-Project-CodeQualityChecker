
namespace CodeQualityChecker
{
    partial class ResultsForm
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.mainPanel = new System.Windows.Forms.Panel();
            this.SpacingChart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.numOfClassesDisplay = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.classCheckDisplay = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.badSemicolonLine = new System.Windows.Forms.RichTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.badSemicolonDisplay = new System.Windows.Forms.Label();
            this.spacingBox = new System.Windows.Forms.GroupBox();
            this.totalLinesDisplay = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.maxIndentDisplay = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.avgIndentDisplay = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.emptyLineDisplay = new System.Windows.Forms.Label();
            this.equalityAssessDisplay = new System.Windows.Forms.RichTextBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.totalComparisonDisplay = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.varEqualNumDisplay = new System.Windows.Forms.Label();
            this.classNameDisplay = new System.Windows.Forms.RichTextBox();
            this.mainPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.SpacingChart)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.spacingBox.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // mainPanel
            // 
            this.mainPanel.Controls.Add(this.groupBox3);
            this.mainPanel.Controls.Add(this.SpacingChart);
            this.mainPanel.Controls.Add(this.groupBox2);
            this.mainPanel.Controls.Add(this.groupBox1);
            this.mainPanel.Controls.Add(this.spacingBox);
            this.mainPanel.Location = new System.Drawing.Point(12, 12);
            this.mainPanel.Name = "mainPanel";
            this.mainPanel.Size = new System.Drawing.Size(776, 426);
            this.mainPanel.TabIndex = 2;
            // 
            // SpacingChart
            // 
            chartArea2.Name = "ChartArea1";
            this.SpacingChart.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.SpacingChart.Legends.Add(legend2);
            this.SpacingChart.Location = new System.Drawing.Point(367, 212);
            this.SpacingChart.Name = "SpacingChart";
            series2.ChartArea = "ChartArea1";
            series2.Legend = "Legend1";
            series2.Name = "Series1";
            this.SpacingChart.Series.Add(series2);
            this.SpacingChart.Size = new System.Drawing.Size(346, 204);
            this.SpacingChart.TabIndex = 2;
            this.SpacingChart.Text = "Code Spacing Chart";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.classNameDisplay);
            this.groupBox2.Controls.Add(this.numOfClassesDisplay);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label14);
            this.groupBox2.Controls.Add(this.classCheckDisplay);
            this.groupBox2.Location = new System.Drawing.Point(9, 220);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(273, 170);
            this.groupBox2.TabIndex = 13;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Naming Conventions:";
            // 
            // numOfClassesDisplay
            // 
            this.numOfClassesDisplay.AutoSize = true;
            this.numOfClassesDisplay.Location = new System.Drawing.Point(200, 30);
            this.numOfClassesDisplay.Name = "numOfClassesDisplay";
            this.numOfClassesDisplay.Size = new System.Drawing.Size(16, 17);
            this.numOfClassesDisplay.TabIndex = 8;
            this.numOfClassesDisplay.Text = "0";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 30);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(137, 17);
            this.label7.TabIndex = 7;
            this.label7.Text = "# of Classes Found: ";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(6, 58);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(188, 17);
            this.label14.TabIndex = 5;
            this.label14.Text = "Classes without CamelCase: ";
            // 
            // classCheckDisplay
            // 
            this.classCheckDisplay.AutoSize = true;
            this.classCheckDisplay.Location = new System.Drawing.Point(200, 58);
            this.classCheckDisplay.Name = "classCheckDisplay";
            this.classCheckDisplay.Size = new System.Drawing.Size(16, 17);
            this.classCheckDisplay.TabIndex = 6;
            this.classCheckDisplay.Text = "0";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Controls.Add(this.badSemicolonLine);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.badSemicolonDisplay);
            this.groupBox1.Location = new System.Drawing.Point(288, 19);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(243, 187);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Potential Misplaced Semicolons:";
            // 
            // badSemicolonLine
            // 
            this.badSemicolonLine.Location = new System.Drawing.Point(9, 104);
            this.badSemicolonLine.Name = "badSemicolonLine";
            this.badSemicolonLine.ReadOnly = true;
            this.badSemicolonLine.Size = new System.Drawing.Size(216, 66);
            this.badSemicolonLine.TabIndex = 8;
            this.badSemicolonLine.Text = "";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(177, 17);
            this.label1.TabIndex = 7;
            this.label1.Text = "(Can also be semicolons in";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(6, 75);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(187, 17);
            this.label12.TabIndex = 5;
            this.label12.Text = "# of Misplaced Semicolons:  ";
            // 
            // badSemicolonDisplay
            // 
            this.badSemicolonDisplay.AutoSize = true;
            this.badSemicolonDisplay.Location = new System.Drawing.Point(199, 75);
            this.badSemicolonDisplay.Name = "badSemicolonDisplay";
            this.badSemicolonDisplay.Size = new System.Drawing.Size(16, 17);
            this.badSemicolonDisplay.TabIndex = 6;
            this.badSemicolonDisplay.Text = "0";
            // 
            // spacingBox
            // 
            this.spacingBox.Controls.Add(this.totalLinesDisplay);
            this.spacingBox.Controls.Add(this.label6);
            this.spacingBox.Controls.Add(this.maxIndentDisplay);
            this.spacingBox.Controls.Add(this.label5);
            this.spacingBox.Controls.Add(this.avgIndentDisplay);
            this.spacingBox.Controls.Add(this.label4);
            this.spacingBox.Controls.Add(this.label3);
            this.spacingBox.Controls.Add(this.emptyLineDisplay);
            this.spacingBox.Location = new System.Drawing.Point(9, 19);
            this.spacingBox.Name = "spacingBox";
            this.spacingBox.Size = new System.Drawing.Size(273, 187);
            this.spacingBox.TabIndex = 7;
            this.spacingBox.TabStop = false;
            this.spacingBox.Text = "Spacing/Indentation:";
            // 
            // totalLinesDisplay
            // 
            this.totalLinesDisplay.AutoSize = true;
            this.totalLinesDisplay.Location = new System.Drawing.Point(177, 64);
            this.totalLinesDisplay.Name = "totalLinesDisplay";
            this.totalLinesDisplay.Size = new System.Drawing.Size(16, 17);
            this.totalLinesDisplay.TabIndex = 12;
            this.totalLinesDisplay.Text = "0";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 64);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(86, 17);
            this.label6.TabIndex = 11;
            this.label6.Text = "Total Lines: ";
            // 
            // maxIndentDisplay
            // 
            this.maxIndentDisplay.AutoSize = true;
            this.maxIndentDisplay.Location = new System.Drawing.Point(177, 121);
            this.maxIndentDisplay.Name = "maxIndentDisplay";
            this.maxIndentDisplay.Size = new System.Drawing.Size(16, 17);
            this.maxIndentDisplay.TabIndex = 10;
            this.maxIndentDisplay.Text = "0";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 121);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(145, 17);
            this.label5.TabIndex = 9;
            this.label5.Text = "Highest Indent Level: ";
            // 
            // avgIndentDisplay
            // 
            this.avgIndentDisplay.AutoSize = true;
            this.avgIndentDisplay.Location = new System.Drawing.Point(177, 93);
            this.avgIndentDisplay.Name = "avgIndentDisplay";
            this.avgIndentDisplay.Size = new System.Drawing.Size(16, 17);
            this.avgIndentDisplay.TabIndex = 8;
            this.avgIndentDisplay.Text = "0";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 93);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(150, 17);
            this.label4.TabIndex = 7;
            this.label4.Text = "Average Indent Level: ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 34);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(129, 17);
            this.label3.TabIndex = 5;
            this.label3.Text = "Total Empty Lines: ";
            // 
            // emptyLineDisplay
            // 
            this.emptyLineDisplay.AutoSize = true;
            this.emptyLineDisplay.Location = new System.Drawing.Point(177, 34);
            this.emptyLineDisplay.Name = "emptyLineDisplay";
            this.emptyLineDisplay.Size = new System.Drawing.Size(16, 17);
            this.emptyLineDisplay.TabIndex = 6;
            this.emptyLineDisplay.Text = "0";
            // 
            // equalityAssessDisplay
            // 
            this.equalityAssessDisplay.Location = new System.Drawing.Point(6, 104);
            this.equalityAssessDisplay.Name = "equalityAssessDisplay";
            this.equalityAssessDisplay.ReadOnly = true;
            this.equalityAssessDisplay.Size = new System.Drawing.Size(224, 66);
            this.equalityAssessDisplay.TabIndex = 4;
            this.equalityAssessDisplay.Text = "";
            // 
            // panel2
            // 
            this.panel2.Enabled = false;
            this.panel2.Location = new System.Drawing.Point(34, 126);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(379, 302);
            this.panel2.TabIndex = 5;
            this.panel2.Visible = false;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.varEqualNumDisplay);
            this.groupBox3.Controls.Add(this.label10);
            this.groupBox3.Controls.Add(this.totalComparisonDisplay);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.equalityAssessDisplay);
            this.groupBox3.Location = new System.Drawing.Point(537, 19);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(236, 187);
            this.groupBox3.TabIndex = 14;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Use of Equality Operators";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(0, 34);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(198, 17);
            this.label2.TabIndex = 5;
            this.label2.Text = "Total Comparison Statements:\r\n";
            // 
            // totalComparisonDisplay
            // 
            this.totalComparisonDisplay.AutoSize = true;
            this.totalComparisonDisplay.Location = new System.Drawing.Point(204, 34);
            this.totalComparisonDisplay.Name = "totalComparisonDisplay";
            this.totalComparisonDisplay.Size = new System.Drawing.Size(16, 17);
            this.totalComparisonDisplay.TabIndex = 6;
            this.totalComparisonDisplay.Text = "0";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(6, 51);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(110, 17);
            this.label9.TabIndex = 9;
            this.label9.Text = "\"for\" statement) ";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(0, 64);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(158, 17);
            this.label10.TabIndex = 7;
            this.label10.Text = "Comparisons using \"=\": ";
            // 
            // varEqualNumDisplay
            // 
            this.varEqualNumDisplay.AutoSize = true;
            this.varEqualNumDisplay.Location = new System.Drawing.Point(204, 64);
            this.varEqualNumDisplay.Name = "varEqualNumDisplay";
            this.varEqualNumDisplay.Size = new System.Drawing.Size(16, 17);
            this.varEqualNumDisplay.TabIndex = 8;
            this.varEqualNumDisplay.Text = "0";
            // 
            // classNameDisplay
            // 
            this.classNameDisplay.Location = new System.Drawing.Point(9, 89);
            this.classNameDisplay.Name = "classNameDisplay";
            this.classNameDisplay.ReadOnly = true;
            this.classNameDisplay.Size = new System.Drawing.Size(216, 66);
            this.classNameDisplay.TabIndex = 10;
            this.classNameDisplay.Text = "";
            // 
            // ResultsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.mainPanel);
            this.Controls.Add(this.panel2);
            this.Name = "ResultsForm";
            this.Text = "Results Form";
            this.Load += new System.EventHandler(this.ResultsForm_Load);
            this.mainPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.SpacingChart)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.spacingBox.ResumeLayout(false);
            this.spacingBox.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Panel mainPanel;
        private System.Windows.Forms.DataVisualization.Charting.Chart SpacingChart;
        private System.Windows.Forms.RichTextBox equalityAssessDisplay;
        private System.Windows.Forms.Label emptyLineDisplay;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.GroupBox spacingBox;
        private System.Windows.Forms.Label avgIndentDisplay;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label maxIndentDisplay;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label totalLinesDisplay;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label badSemicolonDisplay;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox badSemicolonLine;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label classCheckDisplay;
        private System.Windows.Forms.Label numOfClassesDisplay;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label totalComparisonDisplay;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label varEqualNumDisplay;
        private System.Windows.Forms.RichTextBox classNameDisplay;
    }
}