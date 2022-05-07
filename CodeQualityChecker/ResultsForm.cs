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
        private readonly List<CodeFile> fileList;
        public ResultsForm(List<CodeFile> testerFileList)
        {
            InitializeComponent();
            fileList = testerFileList;
        }

        private void ResultsForm_Load(object sender, EventArgs e)
        {
            DrawSpacingGraph();
        }

        private void DrawSpacingGraph()
        {
            spacingChart.Series.Clear();
            List<Series> seriesList = new List<Series>();
            var tempSeries = new Series();
            int i = 0;
            var dataColor = System.Drawing.Color.White;
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
                    ChartType = SeriesChartType.Line
                };
                seriesList.Append(tempSeries);
                this.spacingChart.Series.Add(tempSeries);
            }



        }

        private string TrimFileName(CodeFile file)
        {
            return Path.GetFileName(file.FileName);
        }
    }
}
