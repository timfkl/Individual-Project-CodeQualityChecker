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
using System.Diagnostics;

namespace CodeQualityChecker
{
    public partial class SelectionForm : Form
    {
        private List<CodeFile> fileList;
        private OpenFileDialog fileSelectionDialog = new OpenFileDialog();
        private string doxygenFile;
        private OpenFileDialog doxygenFileSelect = new OpenFileDialog();
        List<string> passedFileNames = new List<string>();

        public SelectionForm()
        {
            fileSelectionDialog = new OpenFileDialog();
            fileList = new List<CodeFile>();
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            InitializeFileSelect();
        }

        

        private void InitializeFileSelect()
        {
            //this.fileSelectionDialog.Filter = "C++ Source(*.cpp)| *.cpp| C/C++ Header(*.h)| *.h| All files(*.*)| *.*";
            this.fileSelectionDialog.Filter = "C++ Source|*.cpp;*.h;*.cc;*.c++;*.C;*.cp;*.cxx;*.hpp;*.hh;*.inl| All files(*.*)| *.*";
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
                        if (!FileDisplay.Text.Contains(file))
                        {
                            fileList.Add(new CodeFile(file));
                            passedFileNames.Add(file);
                            //string temp = File.ReadAllText(file);
                            Console.WriteLine(file);
                            //Console.WriteLine(temp);
                            //string temp = MessageBox.Show();
                        }

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
                
                FileDisplay.Text = String.Join(Environment.NewLine, passedFileNames);
                
            }
            
        }
        private void UnselectButton_Click(object sender, EventArgs e)
        {
            fileList.Clear();
            FileDisplay.Text = "No files selected";
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
                    MessageBox.Show("Cannot display the image: " + doxygenFile.Substring(doxygenFile.LastIndexOf('\\'))
                        + ". You may not have permission to read the file, or " +
                        "it may be corrupt.\n\nReported error: " + ex.Message);
                }
            }
        }

        private void FileDisplay_TextChanged(object sender, EventArgs e)
        {
            
        }
        /**
         * Runs the Tests if there are any files already selected
         */
        private void RunButton_Click(object sender, EventArgs e)
        {
            if (fileList.Count() > 0)
            {
                //runTests = new Tester(fileList);
                //var testResults = runTests.RunTests();
                var m = new ResultsForm(fileList);
                m.Show();
            }
        }
        /**
         * Runs terminal to run Doxygen with the selected directory. Will get back to this later
         */
        private void RunDoxygen_Click(object sender, EventArgs e)
        {
            if (doxygenFile.Contains("doxygen.exe"))
            {
                //https://stackoverflow.com/questions/14243911/how-to-run-doxygen-from-c-sharp-and-pass-in-config-through-stdin
                ProcessStartInfo start = new ProcessStartInfo();
                // Enter in the command line arguments, everything you would enter after the executable name itself
                start.Arguments = " -";
                // Enter the executable to run, including the complete path
                start.FileName = doxygenFile;
                // Do you want to show a console window?
                start.WindowStyle = ProcessWindowStyle.Normal;
                start.CreateNoWindow = false;
                start.RedirectStandardInput = true;
                start.UseShellExecute = false;

                // Run the external process & wait for it to finish
                /*using (Process proc = Process.Start(start))
                {
                    //doxygenProperties is just a dictionary
                    foreach (string key in doxygenProperties.Keys)
                        proc.StandardInput.WriteLine(key + " = " + doxygenProperties[key]);
                    proc.StandardInput.Close();
                    proc.WaitForExit();

                    // Retrieve the app's exit code
                    int exitCode = proc.ExitCode;
                }*/
            }
        }

        
    }
}
