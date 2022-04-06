using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeQualityChecker
{
    class Tester
    {
        

        public Tester()
        {
            
        }

        public void InitializeDoxygen()
        {

        }

        public void CheckSpaces(List<string> fileList)
        {
            string[] textFileContent;
            foreach(string file in fileList)
            {
                textFileContent = File.ReadAllLines(file, Encoding.UTF8);
                CheckSpacesHelper(textFileContent);
            }
        }

        public List<int> CheckSpacesHelper(string[] fileContent)
        {
            List<int> indentList = new List<int>;
            int count = 0;
            foreach( string line in fileContent)
            {
                count = line.TakeWhile(Char.IsWhiteSpace).Count();
                indentList.Add(count);
            }
            return indentList;
        }
    }
}
