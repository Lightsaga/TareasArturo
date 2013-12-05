using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FATSimulatorJorgeDíaz
{
    class MemoryBlock
    {
        public bool isBeingUsed { get; set; }
        public int nextBlockForFileAccess { get; set; }

        public MemoryBlock()
        {
            isBeingUsed = false;
            nextBlockForFileAccess = -2;
        }
        public MemoryBlock(bool IsBeingUsed)
        {
            isBeingUsed = IsBeingUsed;
        }
    }
}
