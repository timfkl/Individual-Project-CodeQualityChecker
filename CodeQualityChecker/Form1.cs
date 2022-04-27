using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Security;

namespace CodeQualityChecker
{
    public partial class Form1 : Form
    {
        private List<string> fileList;
        private OpenFileDialog fileSelectionDialog = new OpenFileDialog();
        private string doxygenFile;
        private OpenFileDialog doxygenFileSelect = new OpenFileDialog();
        Tester runTests;

        public Form1()
        {
            fileSelectionDialog = new OpenFileDialog();
            fileList = new List<string>();
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            InitializeFileSelect();
        }

        

        private void InitializeFileSelect()
        {
            this.fileSelectionDialog.Filter = "Text files(*.txt)| *.txt| All files(*.*)| *.*| C++ Source(*.cpp)| *.cpp| C/C++ Header(*.h)| *.h";
            this.fileSelectionDialog.Multiselect = true;
            this.fileSelectionDialog.Title = "Select Code Files";

            this.doxygenFileSelect.Filter = "All files(*.*) | *.*";
            this.doxygenFileSelect.Title = "Select Doxygen Repository";

        }

        private void FileSelect_Click(object sender, EventArgs e)
        {

            DialogResult dr = this.fileSelectionDialog.ShowDialog();
            if (dr == System.Windows.Forms.DialogResult.OK)
            {
                // Read the files
                foreach (string file in fileSelectionDialog.FileNames)
                {
                    
                    try
                    {
                        fileList.Add(file);
                        //string temp = File.ReadAllText(file);
                        Console.WriteLine(file);
                        //Console.WriteLine(temp);
                        //string temp = MessageBox.Show();
                    }
                    catch (SecurityException ex)
                    {
                        // The user lacks appropriate permissions to read files, discover paths, etc.
                        MessageBox.Show("Security error. Please contact your administrator for details.\n\n" +
                            "Error message: " + ex.Message + "\n\n" +
                            "Details (send to Support):\n\n" + ex.StackTrace
                        );
                        
                    }
                    catch (Exception ex)
                    {
                        // Could not load the image - probably related to Windows file system permissions.
                        MessageBox.Show("Cannot load this file: " + file.Substring(file.LastIndexOf('\\'))
                            + ". You may not have permission to read the file, or " +
                            "it may be corrupt.\n\nReported error: " + ex.Message);
                        
                    }
                }
                
                FileDisplay.Text = String.Join(Environment.NewLine, fileList);
                
            }
            
        }

        private void FindDoxygen_Click(object sender, EventArgs e)
        {
            DialogResult dr = this.doxygenFileSelect.ShowDialog();
            if (dr == System.Windows.Forms.DialogResult.OK){
                try
                {
                    doxygenFile = doxygenFileSelect.FileName;
                }
                catch (SecurityException ex)
                {
                    // The user lacks appropriate permissions to read files, discover paths, etc.
                    MessageBox.Show("Security error. Please contact your administrator for details.\n\n" +
                        "Error message: " + ex.Message + "\n\n" +
                        "Details (send to Support):\n\n" + ex.StackTrace
                    );
                }
                catch (Exception ex)
                {
                    // Could not load the image - probably related to Windows file system permissions.
                    MessageBox.Show("Cannot display the image: " + file.Substring(file.LastIndexOf('\\'))
                        + ". You may not have permission to read the file, or " +
                        "it may be corrupt.\n\nReported error: " + ex.Message);
                }
            }
        }

        private void FileDisplay_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void RunButton_Click(object sender, EventArgs e)
        {
            if (fileList.Count() > 0)
            {
                runTests = new Tester(fileList);
            }
        }

        
    }
}
