using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeQualityChecker
{
    class Tester
    {
        private List<string> fileList;
        private List<string> FileList { get => fileList; set => fileList = value; }

        public Tester(List<string> fileList)
        {
            FileList = fileList;
        }

        public void InitializeDoxygen()
        {

        }
    }
}
