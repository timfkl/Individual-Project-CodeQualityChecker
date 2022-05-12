using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using System.IO;

namespace CodeQualityChecker
{
    public partial class ResultsForm : Form
    {
        private List<CodeFile> fileList;
        public ResultsForm(List<CodeFile> testerFileList)
        {
            while (Controls.Count > 0)
            {
                Controls[0].Dispose();
            }
            InitializeComponent();
            fileList = testerFileList;
        }

        private void ResultsForm_Load(object sender, EventArgs e)
        {
            Tester test = new Tester(ref fileList);
            fileList = test.RunTests();
            RunDisplayGraphics();
            
        }

        private void RunDisplayGraphics()
        {
            IndentationStatistics();
            DisplayEqualityOpAssessment();
            DisplaySemicolonAssessment();
            DisplayNamingConventionTest();
        }

        private void DrawSpacingGraph()
        {
            SpacingChart.Series.Clear();
            List<Series> seriesList = new List<Series>();
            var tempSeries = new Series();
            int i = 0;
            var dataColor = System.Drawing.Color.Red;
            int[] lineNumbers = { 0 };
            int maxValue = 0;
            foreach (CodeFile file in fileList)
            {
                int[] temp = Enumerable.Range(1, file.FileIndentations.Length).ToArray();
                if (temp.Length > lineNumbers.Length)
                {
                    lineNumbers = temp;
                }
                int tempInt = file.FileIndentations.Max();
                if(tempInt > maxValue)
                {
                    maxValue = tempInt;
                }
            }
            //Console.WriteLine(lineNumbers.Length);
            //Console.WriteLine("Maximum Value: " + maxValue);
            SpacingChart.ChartAreas[0].AxisX.Maximum = maxValue;

            foreach (CodeFile file in fileList)
            {

                
                switch (i)
                {
                    case 0:
                        dataColor = System.Drawing.Color.Green;
                        break;
                    case 1:
                        dataColor = System.Drawing.Color.Red;
                        break;
                    case 2:
                        dataColor = System.Drawing.Color.Blue;
                        break;
                    case 3:
                        dataColor = System.Drawing.Color.Yellow;
                        break;
                }
                tempSeries = new Series
                {
                    Name = ("Series " + TrimFileName(file)),
                    Color = dataColor,
                    IsVisibleInLegend = true,
                    IsXValueIndexed = true,
                    ChartType = SeriesChartType.Point
                };
                
                tempSeries.Points.DataBindXY(lineNumbers, file.FileIndentations);
                seriesList.Append(tempSeries);
                this.SpacingChart.Series.Add(tempSeries);
            }



        }

        private void IndentationStatistics()
        {
            int totalEmptyLines = 0;
            double avgIndentLvl = 0.00;
            int maximumIndent = 0;
            int totalLines = 0;
            double avgSum = 0.00;
            foreach (CodeFile file in fileList)
            {
                totalLines += file.FileContent.Length;
                avgSum += file.FileIndentations.Average();
                
                totalEmptyLines += file.EmptyLineCount;
                if(file.FileIndentations.Max() > maximumIndent)
                {
                    maximumIndent = file.FileIndentations.Max();
                }
            }
            avgIndentLvl = avgSum / fileList.Count;
            avgIndentDisplay.Text = Math.Round(avgIndentLvl, 2).ToString(); 
            emptyLineDisplay.Text = totalEmptyLines.ToString();
            maxIndentDisplay.Text = maximumIndent.ToString();
            totalLinesDisplay.Text = totalLines.ToString();
        }
        private string TrimFileName(CodeFile file)
        {
            return Path.GetFileName(file.FileName);
        }
        private void DisplayEqualityOpAssessment()
        {
            equalityAssessDisplay.Text = "";
            int operatorCount = 0;
            List<Tuple<string,int>> trueCount = new List<Tuple<string,int>>();
            string textDisplay = "";
            //string errorList = "";
            foreach (CodeFile file in fileList) {
                operatorCount += file.ComparisonStatements.Count;
                
                foreach (var operation in file.ComparisonStatements)
                {
                    if (operation.Item2 == true)
                    {
                        trueCount.Add(new Tuple<string,int>(file.FileName,operation.Item1));

                    }
                }
                
            }
            textDisplay = trueCount.Count + " out of " + operatorCount + " comparison statements use the wrong equality operator";
            equalityAssessDisplay.Text = textDisplay;
            
        }

        private void DisplaySemicolonAssessment()
        {
            int totalWeirdSemicolons = 0;

            foreach(CodeFile file in fileList)
            {
                totalWeirdSemicolons += file.SemicolonErrors.Count;
                badSemicolonLineDisplay.Text += String.Join<int>(", ", file.SemicolonErrors.AsEnumerable());
                badSemicolonLineDisplay.Text += "\n";
            }
            badSemicolonDisplay.Text = totalWeirdSemicolons.ToString();
            
        }

        private void DisplayNamingConventionTest()
        {
            int numberOfClasses = 0;
            int numberOfBadNames = 0;
            string badClassNames = "";
            foreach(CodeFile file in fileList)
            {
                numberOfClasses +=  file.ClassInstances.Count;
                foreach(var instance in file.ClassInstances)
                {
                    if (instance.Item2)
                    {
                        numberOfBadNames++;
                        badClassNames += "Line: " + instance.Item1 + ": " + instance.Item3 + "\n";
                    }
                }
            }
            classCheckDisplay.Text = numberOfBadNames.ToString();
            numOfClassesDisplay.Text = numberOfClasses.ToString();
        }
    }
}
