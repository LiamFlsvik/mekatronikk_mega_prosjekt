from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'bringup_robot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='orjan',
    maintainer_email='orjan.t.lynnes@ntnu.no',
    description='Bringup file for launching the robot system',
    license='TODO: License declaration',
    entry_points={
        'console_scripts': [],
    },
)