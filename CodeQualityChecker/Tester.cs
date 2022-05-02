using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace CodeQualityChecker
{
    class Tester
    {
        //List of file names
        private readonly List<CodeFile> fileList;
        //List of arrays of file contents separated by line
        //private Tuple<List<string>,List<string[]>> fileListContent;
        

        public Tester(List<CodeFile> fileList)
        {
            this.fileList = fileList;
        }

        public void RunTests() 
        {
            InitializeFileListContent();
            CheckSpaces();
        }
        public void InitializeDoxygen()
        {

        }

        public void InitializeFileListContent()
        {
            foreach (CodeFile file in fileList){
                string[] textFileContent;
                textFileContent = File.ReadAllLines(file.FileName, Encoding.UTF8);
                file.FileContent = textFileContent;
            }
        }
        public void CheckSpaces()
        {
            
            foreach (CodeFile file in fileList)
            {
                Console.WriteLine(file.FileName);
                
                file.FileIndentations = CheckSpacesHelper(file.FileContent);


            }
        }

        public int[] CheckSpacesHelper(string[] fileContent)
        {
            int[] indentList = new int[fileContent.Length];
            int spaceCount = 0;
            int lineNum = 1;
            foreach (string line in fileContent)
            {
                spaceCount = line.TakeWhile(Char.IsWhiteSpace).Count();
                indentList.Append(spaceCount);
                //Console.WriteLine(lineNum + ": " + spaceCount);
                lineNum++;
            }
            
            return indentList;
        }


        public void EqualityOperatorCheck()
        {

        }

        public void MethodFinder()
        {

        }
    }


}
