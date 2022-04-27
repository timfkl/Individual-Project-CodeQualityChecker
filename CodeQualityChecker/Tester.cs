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
        private readonly List<string> fileList;
        //List of arrays of file contents separated by line
        private List<string[]> fileListContent;

        public Tester(List<string> fileList)
        {
            this.fileList = fileList;
        }

        public void RunTests() { }
        public void InitializeDoxygen()
        {

        }

        public void InitializeFileListContent()
        {
            foreach (string file in fileList){
                string[] textFileContent;
                textFileContent = File.ReadAllLines(file, Encoding.UTF8);
                fileListContent.Add(textFileContent);
            }
        }
        public void CheckSpaces()
        {
            int i = 0;
            foreach (string[] fileContent in fileListContent)
            {
                CheckSpacesHelper(fileContent);
            }
        }

        public List<int> CheckSpacesHelper(string[] fileContent)
        {
            List<int> indentList = new List<int>();
            int count = 0;
            foreach (string line in fileContent)
            {
                count = line.TakeWhile(Char.IsWhiteSpace).Count();
                indentList.Add(count);

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
