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
        private OpenFileDialog openFileDialog = new OpenFileDialog();


        public Form1()
        {
            openFileDialog = new OpenFileDialog();
            fileList = new List<string>();
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            InitializeFileSelect();
        }

        private void CheckedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void InitializeFileSelect()
        {
            this.openFileDialog.Filter = "Text files(*.txt)| *.txt| All files(*.*)| *.*| C++ Source(*.cpp)| *.cpp| C/C++ Header(*.h)| *.h";
            this.openFileDialog.Multiselect = true;
            this.openFileDialog.Title = "My Image Browser";
        }

        private void FileSelect_Click(object sender, EventArgs e)
        {

            DialogResult dr = this.openFileDialog.ShowDialog();
            if (dr == System.Windows.Forms.DialogResult.OK)
            {
                // Read the files
                foreach (string file in openFileDialog.FileNames)
                {
                    
                    try
                    {
                        fileList.Add(file);
                        string temp = File.ReadAllText(file);
                        Console.WriteLine(file);
                        Console.WriteLine(temp);
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
                        MessageBox.Show("Cannot display the image: " + file.Substring(file.LastIndexOf('\\'))
                            + ". You may not have permission to read the file, or " +
                            "it may be corrupt.\n\nReported error: " + ex.Message);
                    }
                }
            }
        }
    }
}
