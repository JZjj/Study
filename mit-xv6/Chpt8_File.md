File system

Challenges
1) on-disk data structure: three of named directories and files, to record the identities of the blocks that hold each files content, and to record which areas of the disk are free.
2) crash recovery: risk here is crash interrupt a sequence of updates and leave inconsistent on-disk data structures.
3) maintain invariant
4) in-memory cache of popular blocks

Overview
seven layers:
1) file descriptor
2) pathname layer provides pathname
3) directory layer implements each directory as a special kind of inode whose content is a sequence of directory entries
4) inode layer provides individual files, each represented as an inode with a unique i number and some block holding file data.
5) logging layer allows high layers to wrap updates to several blocks in a transaction, atomically.
6) buffer cache layer caches disk blocks and synchronizes, only one kernel process at a time can modify the data storeded in any block
7) disk layer reads and writes blocks on an virtio hard drive.

block 0 holds the boot sector, block 1 superblock, metadata about the file system (the file system size...)
block 2 starting hold the log, after the log are the inode, with multiple inodes per block. The superblock is filled in by a separate program,mkfs.
well-chosen abstraction at lower layer ease the design of higher ones.

Logging layer
Depending on the order of the disk writes, the crash may either leave an inode with a reference to a content block that is marked free, or it may leave an llocated but unreferenced content block
An xv6 system call does not directly write the on-disk file system data structures. Instead, it places a description of all the disk writes it wishes to make in a log on the disk.




